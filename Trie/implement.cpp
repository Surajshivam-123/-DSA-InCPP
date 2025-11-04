#include<iostream>
using namespace std;

// A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

// Implement the Trie class:

// Trie() Initializes the trie object.
// void insert(String word) Inserts the string word into the trie.
// boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
// boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 

// Example 1:

// Input
// ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
// [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
// Output
// [null, null, true, false, true, null, true]


struct Node{
    Node *links[26];
    bool flag;
    bool containsKey(char ch){
        return links[ch-'a']!=(NULL);
    }
    void put(char ch,Node *node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* node=root;
        for(char ch:word){
            if(!node->containsKey(ch)){
                node->put(ch,new Node());
            }
            node=node->get(ch);
        }
        // moves to the reference line
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node=root;
        for(char ch:word){
            if(!node->containsKey(ch))
                return false;
            node=node->get(ch);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node=root;
        for(char ch:prefix){
            if(!node->containsKey(ch))
                return false;
            node=node->get(ch);
        }
        return true;
    }
};
// implement trie 2;
// Problem statement
// Ninja has to implement a data structure ”TRIE” from scratch. Ninja has to complete some functions.

// 1) Trie(): Ninja has to initialize the object of this “TRIE” data structure.

// 2) insert(“WORD”): Ninja has to insert the string “WORD”  into this “TRIE” data structure.

// 3) countWordsEqualTo(“WORD”): Ninja has to return how many times this “WORD” is present in this “TRIE”.

// 4) countWordsStartingWith(“PREFIX”): Ninjas have to return how many words are there in this “TRIE” that have the string “PREFIX” as a prefix.

// 5) erase(“WORD”): Ninja has to delete one occurrence of the string “WORD” from the “TRIE”.
// Note:

// 1. If erase(“WORD”) function is called then it is guaranteed that the “WORD” is present in the “TRIE”.

// 2. If you are going to use variables with dynamic memory allocation then you need to release the memory associated with them at the end of your solution.
// Can you help Ninja implement the "TRIE" data structure?

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <= “T” <= 50
// 1 <= “N” <= 10000
//  “WORD” = {a to z}
// 1 <= | “WORD” | <= 1000

// Where “T” is the number of test cases, “N” denotes how many times the functions(as discussed above) we call, “WORD” denotes the string on which we have to perform all the operations as we discussed above, and | “WORD” | denotes the length of the string “WORD”.
#include <bits/stdc++.h> 
struct Node{
    Node* links[26];
    int ew=0;
    int cp=0;
public:
    bool containsKey(char ch){
        return links[ch-'a']!=nullptr;
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void increaseCP(){
        cp++;
    }
    void decreaseCP(){
        cp--;
    }
    int getPrefix(){
        return cp;
    }
    void increaseEW(){
        ew++;
    }
    void decreaseEW(){
        ew--;
    }
    int getEW(){
        return ew;
    }
};
class Trie{
    Node* root;
public:

    Trie(){
        root=new Node();
    }

    void insert(string &word){
       Node* node=root;
       for(char ch:word){
           if(!node->containsKey(ch)){
               node->put(ch,new Node());
           }
           node->increaseCP();
           node=node->get(ch);
       }
       node->increaseCP();
       node->increaseEW();
    }

    int countWordsEqualTo(string &word){
        Node* node=root;
        for(char ch:word){
            if(!node->containsKey(ch))
                return 0;
            node=node->get(ch);
        }
        return node->getEW();
    }

    int countWordsStartingWith(string &word){
        Node* node=root;
        for(char ch:word){
            if(!node->containsKey(ch))
                return 0;
            node=node->get(ch);
        }
        return node->getPrefix();
    }

    void erase(string &word){
       Node* node=root;
        for(char ch:word){
            node->decreaseCP();
            node=node->get(ch);
        }
        node->decreaseCP();
        node->decreaseEW();
    }
};

// Longest Valid Word with All Prefixes
// Difficulty: MediumAccuracy: 58.87%Submissions: 6K+Points: 4
// Given an array of strings words[], find the longest string such that every prefix of it is also present in words[]. If multiple strings have the same maximum length, return the lexicographically smallest one.

// If no such string is found, return an empty string.

// Examples:

// Input: words[] = ["p", "pr", "pro", "probl", "problem", "pros", "process", "processor"]
// Output: "pros" 
// Explanation: "pros" is the longest word with all prefixes ("p", "pr", "pro", "pros") present.

class Solution {
    public:
    class Node{
        Node* links[26];
        int endswith=0;
        public:
        bool containsKey(char ch){
            return links[ch-'a']!=NULL;
        }
        void put(char ch,Node* node){
            links[ch-'a']=node;
        }
        void incEW(){
            endswith++;
        }
        Node* get(char ch){
            return links[ch-'a'];
        }
        int getEW(){
            return endswith;
        }
    };
    class Trie{
        Node* root;
        public:
        Trie(){
            root=new Node();
        }
        void insert(string &word){
            Node* node=root;
            for(char ch:word){
                if(!node->containsKey(ch)){
                    node->put(ch,new Node());
                }
                node=node->get(ch);
            }
            node->incEW();
        }
        bool check(string & word){
            Node* node=root;
            for(int i=0;i<word.length()-1;i++){
                node=node->get(word[i]);
                int nump=node->getEW();
                if(nump!=1){
                    return false;
                }
            }
            return true;
        }
    };
    string longestValidWord(vector<string>& words) {
        Trie T;
        for(string str:words){
            T.insert(str);
        }
        int len=0;
        string ans="";
        for(string str:words){
            if(T.check(str) && len<=str.length()){
                if(!(len==str.length() && ans<str)){
                    ans=str;
                    len=str.length();   
                }
            }
        }
        return ans;
    }
};

// time complexity-O(Nxlen)


// Count Distinct Substrings
// Sample Input 1 :
// 2
// sds
// abc
// Sample Output 1 :
// 6
// 7
// Explanation of Sample Input 1 :
// In the first test case, the 6 distinct substrings are { ‘s’,’ d’, ”sd”, ”ds”, ”sds”, “” }

// In the second test case, the 7 distinct substrings are {‘a’, ‘b’, ‘c’, “ab”, “bc”, “abc”, “” }.


// Concept-As we are inserting new element we get new substring
class Node{
    Node* links[26];
    public:
    bool containsKey(char ch){
        return links[ch-'a']!=nullptr;
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
};

int countDistinctSubstrings(string &s)
{   
   int n=s.length();
   int cnt=0;
   Node* root=new Node();
   for(int i=0;i<n;i++){
       Node* node=root;
       for(int j=i;j<n;j++){
           if(!(node->containsKey(s[j]))){
               node->put(s[j],new Node());
               cnt++;
           }
           node=node->get(s[j]);
       }
   }
   return cnt+1;
}