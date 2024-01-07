#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int sizeN, sizeM;

    cin >> sizeN;
    int arrayN[100];
    for (int i = 0; i < sizeN; ++i) {
        cin >> arrayN[i];
    }

    cin >> sizeM;
    int arrayM[100];
    for (int i = 0; i < sizeM; ++i) {
        cin >> arrayM[i];
    }

    sort(arrayN, arrayN + sizeN);
    sort(arrayM, arrayM + sizeM);

    int diffNM[100];
    auto itDiffNM = set_difference(arrayN, arrayN + sizeN, arrayM, arrayM + sizeM, diffNM);
    int sizeDiffNM = distance(diffNM, itDiffNM);

    cout << sizeDiffNM << "\n";
    for (int i = 0; i < sizeDiffNM; ++i) {
        cout << diffNM[i] << " ";
    }
    cout << "\n";

    int diffMN[100];
    auto itDiffMN = set_difference(arrayM, arrayM + sizeM, arrayN, arrayN + sizeN, diffMN);
    int sizeDiffMN = distance(diffMN, itDiffMN);

    cout << sizeDiffMN << "\n";
    for (int i = 0; i < sizeDiffMN; ++i) {
        cout << diffMN[i] << " ";
    }
    cout << "\n";

    int intersection[100];
    auto itIntersection = set_intersection(arrayN, arrayN + sizeN, arrayM, arrayM + sizeM, intersection);
    int sizeIntersection = distance(intersection, itIntersection);

    cout << sizeIntersection << "\n";
    for (int i = 0; i < sizeIntersection; ++i) {
        cout << intersection[i] << " ";
    }
    cout << "\n";

    int Union[200];
    auto itUnion = set_union(arrayN, arrayN + sizeN, arrayM, arrayM + sizeM, Union);
    int sizeUnion = distance(Union, itUnion);

    cout << sizeUnion << "\n";
    for (int i = 0; i < sizeUnion; ++i) {
        cout << Union[i] << " ";
    }
    cout << "\n";

    int symmetricDifference[200];
    auto itSymmetricDiff = set_symmetric_difference(arrayN, arrayN + sizeN, arrayM, arrayM + sizeM, symmetricDifference);
    int sizeSymmetricDiff = distance(symmetricDifference, itSymmetricDiff);

    cout << sizeSymmetricDiff << "\n";
    for (int i = 0; i < sizeSymmetricDiff; ++i) {
        cout << symmetricDifference[i] << " ";
    }
    cout << "\n";

    return 0;
}