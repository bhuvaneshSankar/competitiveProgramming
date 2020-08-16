/*
    Given a non-empty list of words, return the k most frequent elements.

    Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

    Example 1:
    Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
    Output: ["i", "love"]
    Explanation: "i" and "love" are the two most frequent words.
        Note that "i" comes before "love" due to a lower alphabetical order.
    Example 2:
    Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
    Output: ["the", "is", "sunny", "day"]
    Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
        with the number of occurrence being 4, 3, 2 and 1 respectively.

*/

#include <bits/stdc++.h>
#include <map>
#include <vector>
#include <queue>
using namespace std;

map<string, int> wordMap;
class Compare
{
public:
    bool operator()(string s1, string s2)
    {
        auto pr1 = wordMap.find(s1);
        int c1 = pr1->second;
        auto pr2 = wordMap.find(s2);
        int c2 = pr2->second;
        if (c1 == c2)
        {
            int val = s1.compare(s2);
            if (val < 0)
                return true;
            else
                return false;
        }
        return c1 > c2; //comparator returns true then swapping will occur
    }
};
void printPQ(priority_queue<string, vector<string>, Compare> pq)
{
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\n";
}
vector<string> usingPriorityQueue(vector<string> words, int k)
{
    priority_queue<string, vector<string>, Compare> pq;
    for (pair<string, int> pr : wordMap)
    {
        pq.push(pr.first);
        printPQ(pq);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    vector<string> result;
    while (!pq.empty())
    {
        result.push_back(pq.top());
        pq.pop();
    }
    return result;
}
vector<string> topKFrequent(vector<string> &words, int k)
{

    for (string str : words)
    {
        auto itr = wordMap.find(str);
        if (itr == wordMap.end())
        {
            wordMap.insert({str, 1});
        }
        else
        {
            itr->second += 1;
        }
    }
    return usingPriorityQueue(words, k);

    //    without priority queue
    //vector<string> result;
    // map<int, vector<string>> reverseMap;
    // for (pair<string, int> pr : wordMap)
    // {
    //     reverseMap[pr.second].push_back(pr.first);
    // }
    // map<int, vector<string>>::reverse_iterator itr;
    // for (itr = reverseMap.rbegin(); itr != reverseMap.rend(); itr++)
    // {
    //     if (k <= 0)
    //     {
    //         break;
    //     }
    //     vector<string> v = itr->second;
    //     for (int j = 0; j < v.size() && k > 0; j++)
    //     {
    //         result.push_back(v[j]);
    //         k--;
    //     }
    // }
    //return result;
}
int main()
{
    //  vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    vector<string> words = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    int k = 4;
    vector<string> result = topKFrequent(words, k);
    reverse(result.begin(), result.end());
    for (string str : result)
    {
        cout << str << " ";
    }
}

/* using heap */
/*
    static bool comparator(pair<string, int> it1, pair<string, int> it2)
    {
        if(it1.second == it2.second){
            int val = it1.first.compare(it2.first);
            if(val<0){
                return false;
            }
            else{
                return true;
            }
        }
        else{
            return it1.second < it2.second;
        }
    } 
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> wordMap;
        vector<string> result;
        for(string str : words){
            auto itr = wordMap.find(str);
            if(itr==wordMap.end()){
                wordMap.insert({str, 1});
            }
            else{
                itr->second += 1;
            }
        }
        vector<pair<string,int>> hp;
        for(pair<string, int> pr : wordMap){
            hp.push_back(pr);
        }
        make_heap(hp.begin(), hp.end(), comparator);
        for(; k>0; k--){
            result.push_back(hp.front().first);
            pop_heap(hp.begin(), hp.end(), comparator);
            hp.pop_back();
        }
        return result;
    }

*/