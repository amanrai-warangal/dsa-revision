#include"TrieNode.h"
using namespace std;

class Trie{
    TrieNode *root;

    public:

        Trie(){
            root = new TrieNode();
        }

        void insert(string word){
            TrieNode *currNode = root;

            for(int i=0;i<word.size();i++){
                if(!currNode->containsKey(word[i])){
                    currNode->put(word[i]);
                }

                currNode = currNode->get(word[i]);
            }

            currNode->increaseEnd();
        }

        bool search(string word){
            TrieNode *currNode = root;

            for(int i=0;i<word.size();i++){
                if(!currNode->containsKey(word[i])){
                    return false;
                }

                currNode = currNode->get(word[i]);
            }

            return currNode->getEndCnt() != 0;
        }

        bool startsWith(string word){
            TrieNode *currNode = root;

            for(int i=0;i<word.size();i++){
                if(!currNode->containsKey(word[i])){
                    return false;
                }

                currNode = currNode->get(word[i]);
            }

            return true;
        }

        int countWordsEqualTo(string word){
            TrieNode *currNode = root;

            for(int i=0;i<word.size();i++){
                if(!currNode->containsKey(word[i])){
                    return false;
                }

                currNode = currNode->get(word[i]);
            }

            return currNode->getEndCnt();
        }

        void erase(string word){
            TrieNode *currNode = root;

            for(int i=0;i<word.size();i++){
                if(!currNode->containsKey(word[i])){
                    return;
                }

                currNode = currNode->get(word[i]);
            }

            currNode->deleteWord();
        }
};