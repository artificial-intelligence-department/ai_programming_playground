#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    using namespace std;

    int N, M;

    cin >> N;
    vector <int> arrayN(N);
    for (int i = 0; i < N; ++i) {
        cin >> arrayN[i];
    }

    cin >> M;
    vector <int> arrayM(M);
    for (int i = 0; i < M; ++i) {
        cin >> arrayM[i];
    }

    sort(arrayN.begin(), arrayN.end());
    sort(arrayM.begin(), arrayM.end());

    vector<int> differenceNM;
    set_difference(arrayN.begin(), arrayN.end(), arrayM.begin(), arrayM.end(), back_inserter(differenceNM));
    cout << differenceNM.size() << endl;
    for (int i = 0; i<differenceNM.size();i++) {
        cout << differenceNM[i] << " ";
    }
    cout << endl;

    vector<int> differenceMN;
    set_difference(arrayM.begin(), arrayM.end(), arrayN.begin(), arrayN.end(), back_inserter(differenceMN));
    cout << differenceMN.size() << endl;
    for (int i = 0; i<differenceMN.size();i++) {
        cout << differenceMN[i] << " ";
    }
    cout << endl;

    vector<int> intersection;
    set_intersection(arrayN.begin(), arrayN.end(), arrayM.begin(), arrayM.end(), back_inserter(intersection));
    cout << intersection.size() << endl;
    for (int i = 0; i<intersection.size();i++) {
        cout << intersection[i] << " ";
    }
    cout << endl;

    vector<int> Union;
    set_union(arrayN.begin(), arrayN.end(), arrayM.begin(), arrayM.end(), back_inserter(Union));
    cout << Union.size() << endl;
    for (int i = 0; i<Union.size();i++) {
        cout << Union[i] << " ";
    }
    cout << endl;

    vector<int> symmetricDifference;
    set_symmetric_difference(arrayN.begin(), arrayN.end(), arrayM.begin(), arrayM.end(), back_inserter(symmetricDifference));
    cout << symmetricDifference.size() << endl;
    for (int i = 0; i<symmetricDifference.size();i++) {
        cout << symmetricDifference[i] << " ";
    }
    cout << endl;
}
