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

double PmergeMe::getCurrentTimeMicro()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000.0) + tv.tv_usec;
}

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

void PmergeMe::printResults() const
{
    std::cout << "Time to process a range of "
              << _vector.size()
              << " elements with std::vector : "
              << _timeVector << " us" << std::endl;

    std::cout << "Time to process a range of "
              << _deque.size()
              << " elements with std::deque  : "
              << _timeDeque << " us" << std::endl;
}

void    PmergeMe::printVector( void ) const
{
    std::cout << "Vector: ";
    for (size_t x = 0; x < _vector.size(); x++)
        std::cout << _vector[x] << " ";
    std::cout << std::endl;
}

void    PmergeMe::printDeque( void ) const 
{
    std::cout << "Deque: ";
    for (size_t x = 0; x < _deque.size(); x++)
        std::cout << _deque[x] << " ";
    std::cout << std::endl;
}

void PmergeMe::sort()
{
    if (_vector.size() <= 1 || _deque.size() <= 1)
        return;

    double startVector = getCurrentTimeMicro();
    sortVector();
    double endVector = getCurrentTimeMicro();
    _timeVector = endVector - startVector;

    double startDeque = getCurrentTimeMicro();
    sortDeque();
    double endDeque = getCurrentTimeMicro();
    _timeDeque = endDeque - startDeque;
}

size_t   PmergeMe::jacobsthal(size_t n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

void PmergeMe::sortVector()
{
    std::vector<std::pair<int, int> >   pairs;
    int                                 straggler = 0;
    bool                                hasStraggler = false;

    pairs = makePairsVector(_vector, straggler, hasStraggler);

    std::vector<int> sortedMaiores = mergeInsertVector(pairs);

    // copia o resultado para _vector
    _vector.clear();
    for (size_t i = 0; i < sortedMaiores.size(); ++i)
        _vector.push_back(sortedMaiores[i]);

    // inserir o straggler do top-level (se houver)
    if (hasStraggler)
    {
        std::vector<int>::iterator insertPos = std::lower_bound(_vector.begin(), _vector.end(), straggler);
        _vector.insert(insertPos, straggler);
    }
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
    // CASO BASE
    if (pairs.size() == 0)
        return std::vector<int>();
    
    if (pairs.size() == 1)
    {
        std::vector<int> result;
        result.push_back(pairs[0].second);
        result.push_back(pairs[0].first);
        return result;
    }

    // PASSO 1: extrair maiores
    std::vector<int> maiores;
    for (size_t i = 0; i < pairs.size(); ++i)
        maiores.push_back(pairs[i].first);

    // PASSO 2: emparelhar maiores
    int subStraggler = 0;
    bool subHasStraggler = false;
    std::vector<std::pair<int, int> > subPairs = 
        makePairsVector(maiores, subStraggler, subHasStraggler);

    // PASSO 3: recursão
    std::vector<int> sortedMaiores = mergeInsertVector(subPairs);

    // PASSO 4: reordenar pairs conforme sortedMaiores
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

    // PASSO 5: construir chain inicial
    std::vector<int> chain;
    chain.push_back(reorderedPairs[0].second);
    for (size_t i = 0; i < reorderedPairs.size(); ++i)
        chain.push_back(reorderedPairs[i].first);

    // ✅ NOVO PASSO 5.5: inserir o subStraggler antes dos pendants
    // (porque ele é um "maior" que faz parte da chain)
    if (subHasStraggler)
    {
        // procurar o par correspondente ao subStraggler nos pairs originais
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (pairs[j].first == subStraggler)
            {
                // adicionar este par a reorderedPairs (no fim)
                reorderedPairs.push_back(pairs[j]);
                // inserir o maior do par (subStraggler) na chain por binary search
                std::vector<int>::iterator pos = 
                    std::lower_bound(chain.begin(), chain.end(), subStraggler);
                chain.insert(pos, subStraggler);
                break;
            }
        }
    }

    // PASSO 6: inserir pendants restantes por ordem de Jacobsthal
    size_t numPendants = reorderedPairs.size();
    std::vector<size_t> order = generateJacobsthalOrderVector(numPendants);
    
    for (size_t i = 0; i < order.size(); ++i)
    {
        size_t idx = order[i] - 1;
        int pendant = reorderedPairs[idx].second;
        int anchor = reorderedPairs[idx].first;
        insertPendantVector(chain, pendant, anchor);
    }

    // ✅ PASSO 7 REMOVIDO: o subStraggler já foi inserido no passo 5.5

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

//==============================================================================
//                           DEQUE IMPLEMENTATION
//==============================================================================

void PmergeMe::sortDeque()
{
    std::deque<std::pair<int, int> >    pairs;
    int                                 straggler = 0;
    bool                                hasStraggler = false;

    pairs = makePairsDeque(_deque, straggler, hasStraggler);

    std::deque<int> sortedMaiores = mergeInsertDeque(pairs);

    // copia o resultado para _deque
    _deque.clear();
    for (size_t i = 0; i < sortedMaiores.size(); ++i)
        _deque.push_back(sortedMaiores[i]);

    // inserir o straggler do top-level (se houver)
    if (hasStraggler)
    {
        std::deque<int>::iterator insertPos = std::lower_bound(_deque.begin(), _deque.end(), straggler);
        _deque.insert(insertPos, straggler);
    }
}

std::deque<std::pair<int, int> > PmergeMe::makePairsDeque(const std::deque<int> &input, int &straggler, bool &hasStraggler)
{
    std::deque<std::pair<int, int> > pairs;

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
        hasStraggler = true;
        straggler = input.back();
    }
    else
    {
        hasStraggler = false;
        straggler = 0;
    }
    return pairs;
}

std::deque<int> PmergeMe::mergeInsertDeque(std::deque<std::pair<int, int> > &pairs)
{
    // CASO BASE
    if (pairs.size() == 0)
        return std::deque<int>();

    if (pairs.size() == 1)
    {
        std::deque<int> result;
        result.push_back(pairs[0].second);
        result.push_back(pairs[0].first);
        return result;
    }

    // PASSO 1: extrair maiores
    std::deque<int> maiores;
    for (size_t i = 0; i < pairs.size(); ++i)
        maiores.push_back(pairs[i].first);

    // PASSO 2: emparelhar maiores
    int subStraggler = 0;
    bool subHasStraggler = false;
    std::deque<std::pair<int, int> > subPairs = 
        makePairsDeque(maiores, subStraggler, subHasStraggler);

    // PASSO 3: recursão
    std::deque<int> sortedMaiores = mergeInsertDeque(subPairs);

    // PASSO 4: reordenar pairs conforme sortedMaiores
    std::deque<std::pair<int, int> > reorderedPairs;
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

    // PASSO 5: construir chain inicial
    std::deque<int> chain;
    chain.push_back(reorderedPairs[0].second);
    for (size_t i = 0; i < reorderedPairs.size(); ++i)
        chain.push_back(reorderedPairs[i].first);

    // PASSO 5.5: inserir o subStraggler antes dos pendants
    if (subHasStraggler)
    {
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (pairs[j].first == subStraggler)
            {
                reorderedPairs.push_back(pairs[j]);
                std::deque<int>::iterator pos = 
                    std::lower_bound(chain.begin(), chain.end(), subStraggler);
                chain.insert(pos, subStraggler);
                break;
            }
        }
    }

    // PASSO 6: inserir pendants restantes por ordem de Jacobsthal
    size_t numPendants = reorderedPairs.size();
    std::deque<size_t> order = generateJacobsthalOrderDeque(numPendants);

    for (size_t i = 0; i < order.size(); ++i)
    {
        size_t idx = order[i] - 1;
        int pendant = reorderedPairs[idx].second;
        int anchor = reorderedPairs[idx].first;
        insertPendantDeque(chain, pendant, anchor);
    }

    return chain;
}

std::deque<size_t> PmergeMe::generateJacobsthalOrderDeque(size_t n)
{
    std::deque<size_t> order;

    if (n <= 1)
        return order;
    size_t k = 3;
    size_t prevJ = 1;

    while (true)
    {
        size_t currJ = jacobsthal(k);

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

void PmergeMe::insertPendantDeque(std::deque<int> &chain, int pendant, int anchor)
{
    std::deque<int>::iterator anchorPos = std::find(chain.begin(), chain.end(), anchor);

    std::deque<int>::iterator insertPos = std::lower_bound(chain.begin(), anchorPos, pendant);

    chain.insert(insertPos, pendant);
}