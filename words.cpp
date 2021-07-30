/**
 * Computer Programming 2 (COMP2711, COMP8801)
 * Practical 4: Words
 */

#include <iostream>
#include <string>
#include <unistd.h>
//#include <vector>
#include <algorithm>
#include "MyVector.h"

using namespace std;

struct WordInfo{
    string text;
    int count;
    //WordInfo(){}
   /* WordInfo(string text, int count){
        (*this).text = text;
        this->count=count;
    }*/
};
struct match {
    WordInfo inp_;
    explicit match(const WordInfo& inp) { inp_ = inp; }
    bool operator()(const WordInfo& vWord) const {
        return inp_.text==vWord.text;
    }
};
struct compare {
    bool operator() (const WordInfo& a, const WordInfo& b) {
        return (a.text<b.text);
    }
} compare;

int main(int argc, char** argv)
{
    enum {
        total,
        unique,
        individual
    } mode = total;

    for (int c; (c = getopt(argc, argv, "tui")) != -1;) {
        switch (c) {
        case 't':
            mode = total;
            break;
        case 'u':
            mode = unique;
            break;
        case 'i':
            mode = individual;
            break;
        }
    }
    argc -= optind;
    argv += optind;

    string word;
    MyVector<WordInfo> uniq;
    MyVector<WordInfo>::iterator it;

    int ttl = 0;
    while (cin >> word) {
        ttl++;
        WordInfo neWord;
        neWord.text=word;
        neWord.count=1;
            // find in container<T>
            it = find_if(uniq.begin(), uniq.end(), match(neWord));
            if(it == uniq.end()){
                uniq.insert(uniq.end(),neWord);
            } else {
                it->count++;
            }

            /*for(it = uniq.begin(); it<uniq.end(); it++) {
                if(it->text==word){
                    it->count++;uniq.insert()
                    break;
                } else {
                    WordInfo neWord;
                    neWord.text=word;
                    neWord.count=1;
                    uniq.insert(uniq.end(),neWord);
                    break;
                }
            }*/

    }

    switch (mode) {
    case total:
        cout << "Total: " << ttl << '\n';
        break;
    case unique:
        cout << "Unique: " << uniq.size() << '\n';
        break;
    case individual:
        sort(uniq.begin(),uniq.end(),compare);
        for(it = uniq.begin(); it<uniq.end(); it++) {
            cout << it->text << ": " << it->count << endl;
            }
        break;
    }

    return 0;
}
