#ifndef NFA_H
#define NFA_h

#include <vector>
#include <string>
#include <fstream>
#include <unordered_set>
#include <set>
#include <iostream>

class NFA
{
    int statesNumber, sigma;
    std::vector<int> F;
    int q0;
    std::vector<std::vector< std::pair<int, int> >> M;

public:
    NFA(const std::string& input_file);
    void ToDFA(const std::string& output_file);

private:
    const int lambda = -1;
    std::unordered_set<long long> viz;

    std::vector<long long> nF;
    std::vector< std::pair< std::pair<long long, long long>, int > > G;

    long long mask(std::set<int>& Q);
    void add_edges(std::set<int>& Q, int q, int c);
    void DFS(std::set<int> Q);
    void print(long long m, std::ostream& os);
    void isFinalState(std::set<int>& Q, int m);
};

#endif // NFA_H

