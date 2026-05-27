#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe( const PmergeMe& copy )
{
    *this = copy;
}

PmergeMe&   PmergeMe::operator=( const PmergeMe& copy)
{
    if (this != &copy)
    {
        _vector = copy._vector;
        _deque = copy._deque;
    }
    return (*this);
}

PmergeMe::~PmergeMe(){}

void    PmergeMe::parsingInput( int ac, char **av )
{
    if (ac < 2)
        throw (Error("usage ./PmergeMe <positive numbers>"));

    std::set<int> seen;
    for (int i = 1; i < ac; i++)
    {
        std::string arg(av[i]);

        if (arg.empty())
            throw(Error("empty string"));
        if (arg[0] == '-' || arg[0] == '+')
            throw (Error("only positive numbers without sign"));
        for (size_t j = 0; j < arg.size(); j++)
            if (!std::isdigit(arg[j]))
                throw(Error("only numbers"));
        
        char *end;
        errno = 0;
        long val = strtol(arg.c_str(), &end, 10);
        if (*end != '\0' || errno == ERANGE)
            throw (Error("invalid number"));
        if (val <= 0)
            throw(Error("only positive numbers"));
        if (val > INT_MAX)
            throw (Error("number too large"));

        int n = static_cast<int>(val);
        if (!seen.insert(n).second)
            throw(Error("duplicate value"));
        _vector.push_back(n);
        _deque.push_back(n);
    }
}

void    PmergeMe::printVector( void ) const
{
    for (size_t x = 0; x < _vector.size(); x++)
        std::cout << "Vector[ " << x << " ]: " << _vector[x] << std::endl;
}

void    PmergeMe::printDeque( void ) const 
{
    for (size_t x = 0; x < _deque.size(); x++)
        std::cout << "Deque[ " << x << " ]: " << _deque[x] << std::endl;
}

void    PmergeMe::sort() 
{
    if (_vector.size() <= 1 || _deque.size() <= 1)
        return ;
    sortVector();
    //sortDeque();
}

size_t   PmergeMe::jacobsthal(size_t n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

void    PmergeMe::sortVector()
{
    std::cout << "Vector Sort " << std::endl;
    std::cout << "Vector Size: " << _vector.size() << std::endl;

    std::vector<std::pair<int, int> >   pairs;
    int                                 straggler = 0;
    bool                                hasStraggler = false;

    pairs = makePairsVector(_vector, straggler, hasStraggler);
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ")" << std::endl;
    }
    if (hasStraggler)
        std::cout << "Straggler: " << straggler << std::endl;
    else
        std::cout << "Sem straggler" << std::endl;

    std::cout << "\n--- RECURSÃO ---" << std::endl;
    std::vector<int> sortedMaiores = mergeInsertVector(pairs);
    std::cout << "--- FIM DA RECURSÃO ---\n" << std::endl;

    for (size_t i = 0; i < sortedMaiores.size(); ++i)
        _vector[i] = sortedMaiores[i];

}
/**
 * Esta funcao cria os pares para o algoritmo Ford-Jonhnson utilizar
 * Faz a divisao do numero de elementos total do vetor por 2 para obter o numero de pares, caso se impar esse numero
 * ficara guardado com straggler e nao afetera o numero de pares
 * Depois e feita uma comparacao entre cada par de numeros para colocar o maior sempre na primeira posicao de cada par
 * 
 * @param {input} vector com o numeros desordenados, {stranggler} onde guarda o numero que fica dec fora, {hasStranggler} booleano caso exista um stranggler
 * @returns
 */
std::vector<std::pair<int, int> > PmergeMe::makePairsVector( const std::vector<int> &input, int &stranggler, bool &hasStranggler)
{
    std::vector<std::pair<int, int> > pairs;

    size_t pairCount = input.size() / 2;

    for (size_t i = 0; i < pairCount; ++i)
    {
        int first = input[i * 2];
        int second = input[i * 2 + 1];
        
        if (first > second)
            pairs.push_back(std::make_pair(first, second));
        else
            pairs.push_back(std::make_pair(second, first));
    }

    if (input.size() % 2 != 0)
    {
        hasStranggler = true;
        stranggler = input.back();
    }
    else
    {
        hasStranggler = false;
        stranggler = 0;
    }
    return pairs;
}
std::vector<int> PmergeMe::mergeInsertVector(std::vector<std::pair<int, int> > &pairs)
{
    // ===== CASO BASE =====
    if (pairs.size() == 0)
        return std::vector<int>();
    
    if (pairs.size() == 1)
    {
        // 1 par: devolve [menor, maior] já ordenado
        std::vector<int> result;
        result.push_back(pairs[0].second);   // menor primeiro
        result.push_back(pairs[0].first);    // maior depois
        return result;
    }

    // ===== PASSO 1: extrair maiores =====
    std::vector<int> maiores;
    for (size_t i = 0; i < pairs.size(); ++i)
        maiores.push_back(pairs[i].first);

    // ===== PASSO 2: emparelhar maiores (sub-problema) =====
    int subStraggler = 0;
    bool subHasStraggler = false;
    std::vector<std::pair<int, int> > subPairs = 
        makePairsVector(maiores, subStraggler, subHasStraggler);

    // ===== PASSO 3: recursão =====
    std::vector<int> sortedMaiores = mergeInsertVector(subPairs);

    // ===== PASSO 4: reordenar pairs atuais conforme sortedMaiores =====
    // Para cada elemento em sortedMaiores, encontrar o par correspondente
    // e construir o novo vector de pairs reordenados
    std::vector<std::pair<int, int> > reorderedPairs;
    for (size_t i = 0; i < sortedMaiores.size(); ++i)
    {
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (pairs[j].first == sortedMaiores[i])
            {
                reorderedPairs.push_back(pairs[j]);
                break;
            }
        }
    }

    // ===== PASSO 5: construir main chain inicial =====
    // chain = [menor do primeiro par, todos os maiores ordenados]
    std::vector<int> chain;
    chain.push_back(reorderedPairs[0].second);   // primeiro menor (sem binary search!)
    for (size_t i = 0; i < reorderedPairs.size(); ++i)
        chain.push_back(reorderedPairs[i].first);

    // ===== PASSO 6: inserir pendants restantes por ordem de Jacobsthal =====
    // pendants restantes são os menores dos pares 2, 3, 4, ... (1-based)
    // ou seja, índices 1, 2, 3, ... (0-based)
    size_t numPendants = reorderedPairs.size();  // total de pendants (incluindo o primeiro)
    std::vector<size_t> order = generateJacobsthalOrderVector(numPendants);
    
    for (size_t i = 0; i < order.size(); ++i)
    {
        // order[i] é 1-based, converter para 0-based
        size_t idx = order[i] - 1;
        int pendant = reorderedPairs[idx].second;
        int anchor = reorderedPairs[idx].first;
        insertPendantVector(chain, pendant, anchor);
    }

    // ===== PASSO 7: inserir straggler deste nível (se houver) =====
    if (subHasStraggler)
    {
        // straggler é um "maior" sem par, não tem anchor — binary search em toda a chain
        std::vector<int>::iterator insertPos = 
            std::lower_bound(chain.begin(), chain.end(), subStraggler);
        chain.insert(insertPos, subStraggler);
    }

    return chain;
}

std::vector<size_t> PmergeMe::generateJacobsthalOrderVector(size_t n)
{
    std::vector<size_t> order;

    if (n <= 1)
        return order;
    size_t k = 3;
    size_t prevJ = 1;

    while (true)
    {
        size_t  currJ = jacobsthal(k);

        if (currJ >= n)
        {
            for (size_t i = n; i > prevJ; --i)
                order.push_back(i);
            break;
        }
        for (size_t i = currJ; i > prevJ; --i)
            order.push_back(i);
        prevJ = currJ;
        ++k;
    }
    return order;
}
void PmergeMe::insertPendantVector(std::vector<int> &chain, int pendant, int anchor)
{
    std::vector<int>::iterator anchorPos = std::find(chain.begin(), chain.end(), anchor);
    
    std::vector<int>::iterator insertPos = std::lower_bound(chain.begin(), anchorPos, pendant);
    
    chain.insert(insertPos, pendant);
}
