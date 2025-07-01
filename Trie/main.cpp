#include"Trie.h"
using namespace std;

int main(int argc,char **argv){
    Trie dictionary;
    int q;
    while(true){
        
        cout << "Enter the query type (1,2,3,4,5) : ";
        cin >> q;

        if(q == 1){
            string word;
            cout << "Enter Word : ";
            cin >> word;
            dictionary.insert(word);
        }
        else if(q == 2){
            string word;
            cout << "Enter Word : ";
            cin >> word;
            cout << dictionary.search(word) << endl;
        }
        else if(q == 3){
            string prefix;
            cout << "Enter Prefix : ";
            cin >> prefix;
            cout << dictionary.startsWith(prefix) << endl;
        }
        else if(q == 4){
            string word;
            cout << "Enter Word : ";
            cin >> word;
            cout << dictionary.countWordsEqualTo(word) << endl;
        }
        else if(q == 5){
            string word;
            cout << "Enter Word : ";
            cin >> word;
            dictionary.erase(word);
        }

        else 
            break;
    }
}
