#include<iostream>

class TrieNode{
    TrieNode *links[26];
    int cntEndsWith;

    public:

        TrieNode(){
            cntEndsWith = 0;
            for(int i=0;i<26;i++)
                links[i] = NULL;
        }

        bool containsKey(char ch){
            return (links[ch-'a'] != NULL);
        }

        void put(char ch){
            links[ch-'a'] = new TrieNode();
        }

        TrieNode *get(char ch){
            return links[ch-'a'];
        }

        void increaseEnd(){
            cntEndsWith++;
        }

        int getEndCnt(){
            return cntEndsWith;
        }

        bool deleteWord(){
            cntEndsWith--;
        }


};