#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define ll long long
#define fo(i, n) for (int i = 0; i < n; i++)
#define deb(a) cout << #a << " - " << a << "\n"
#define deb2(a, b) cout << #a << " - " << a << " " << #b << " - " << b << "\n"
#define vi vector<int>
#define itriv vector<vector<int>>::iterator

using namespace std;

int comp(vector<int> a, vector<int> b)
{
    return a[1] < b[1];
}
void shift(vector<vi> &people, int curr, int count) //o(curr - people[curr][1]) => difference between the current position and number of ppl those who have more height than the current one
{
    int diff = count - people[curr][1];
    int targetPos = curr - diff;
    deb(diff);
    deb(targetPos);
    vi currentPpl = people[curr];
    int pos = curr;
    int prev = curr - 1;
    fo(i, diff)
    {
        vi temp = people[prev];
        people[prev] = people[pos];
        people[pos] = temp;
        pos = prev;
        prev = pos - 1;
    }
}
void findCorrectPos(int curr, vector<vi> &people) //o(n)
{
    int count = 0;
    fo(i, curr)
    {
        if (people[i][0] >= people[curr][0])
            count++;
    }
    if (count > people[curr][1])
    {
        shift(people, curr, count);
    }
}
vector<vi> reconstructQueue(vector<vi> &people)
{
    //my logic - 1184ms
    sort(people.begin(), people.end(), comp); //o(nlogn)
    itriv itr;
    fo(i, people.size()) //o(n)
    {
        if (i != 0)
        {
            findCorrectPos(i, people);
        }
    }
    return people;
}
int compHeight(vi a, vi b)
{
    return a[0] < b[0];
}
vector<vi> reconstructQueueOptimized(vector<vi> &people)
{
    //runtime - 156ms
    sort(people.begin(), people.end(), compHeight); //o(nlogn)
    int n = people.size();
    int toBePlaced = n;
    int curr = 0;
    vector<vi> result(n);
    fo(i, n)
    {
        vi a = {-1, -1};
        result[i] = a;
    }
    bool flag[n] = {false};
    while (toBePlaced > 0)
    {
        int pos = 0;
        int greaterPpl = people[curr][1];
        int count = 0;
        int i = 0;
        while (count < greaterPpl)
        {
            if (flag[pos] == false)
            {
                count++;
                pos++;
            }
            else if (flag[pos] == true && result[pos][0] >= people[curr][0])
            {
                count++;
                pos++;
            }
            else
            {
                pos++;
            }
        }

        while (pos < n && flag[pos] == true && result[pos][0] < people[curr][0])
        {
            pos++;
        }
        result[pos] = people[curr];
        curr++;
        toBePlaced--;
        flag[pos] = true;
    }
    return result;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<vi> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    //   people = reconstructQueue(people);
    vector<vi> recons = reconstructQueueOptimized(people);
    fo(i, recons.size())
    {
        deb2(recons[i][0], recons[i][1]);
    }
}