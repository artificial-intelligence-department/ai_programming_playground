#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void displayVect(vector<int> &vect)
{
    cout << vect.size() << endl;

    for (int n : vect)
    {
        cout << n << " ";
    }
    cout << endl;
    cout << endl;
}
void displayDiff(vector<int> first, vector<int> second, vector<int> &diff)
{

    for (size_t i = 0; i < first.size(); i++)
    {

        for (size_t j = 0; j < second.size(); j++)
        {

            if (first[i] == second[j])
            {

                first[i] = 0;
                second[j] = 0;
            }
        }
    }
    first.erase(remove(first.begin(), first.end(), 0), first.end());
    displayVect(first);

    for (int n : first)
    {
        diff.push_back(n);
    }
}

void displayEqual(vector<int> first, vector<int> second)
{
    vector<int> same;

    for (size_t i = 0; i < first.size(); i++)
    {

        for (int j = 0; j < second.size(); j++)
        {

            if (first[i] == second[j])
            {

                same.push_back(first[i]);
                first[i] = 0;
                second[j] = 0;
            }
        }
    }
    same.erase(remove(same.begin(), same.end(), 0), same.end());
    displayVect(same);
}

void displayUn(vector<int> first, vector<int> &second, vector<int> &secDiff)
{

    first.insert(first.end(), secDiff.begin(), secDiff.end());
    sort(first.begin(), first.end());
    displayVect(first);
}
void displaySymdiff(vector<int> &firstDiff, vector<int> &secDiff)
{

    for (size_t i = 0; i < secDiff.size(); i++)
    {

        firstDiff.push_back(secDiff[i]);
    }
    sort(firstDiff.begin(), firstDiff.end());

    displayVect(firstDiff);
}

int main(int argc, char const *argv[])
{

    int N{0};
    int M{0};
    cin >> N;
    if (!(1 <= N && N <= 100))
    {
        return 0;
    }

    vector<int> nAr;
    vector<int> mAr;
    vector<int> firstDiff;
    vector<int> secDiff;

    for (size_t i = 0; i < N; i++)
    {
        int ni;
        cin >> ni;
        nAr.push_back(ni);
    }
    cin >> M;
    if (!(1 <= M && M <= 100))
    {
        return 0;
    }
    for (size_t i = 0; i < M; i++)
    {
        int mi;
        cin >> mi;
        mAr.push_back(mi);
    }

    sort(nAr.begin(), nAr.end());
    sort(mAr.begin(), mAr.end());

    displayDiff(nAr, mAr, firstDiff);
    displayDiff(mAr, nAr, secDiff);

    displayEqual(nAr, mAr);
    displayUn(nAr, mAr, secDiff);
    displaySymdiff(firstDiff, secDiff);

    return 0;
}