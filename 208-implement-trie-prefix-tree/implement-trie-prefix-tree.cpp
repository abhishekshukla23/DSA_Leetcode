class Trie {
public:
   string s="";
    Trie() {
        s+='#';
    }
    
    void insert(string word) {
        s+=word;
        s+='#';
    }
    
    bool search(string word) {
        if(s.find('#'+word+'#')!=string::npos){
          return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        if(s.find('#'+prefix)!=string::npos) {
            return true;
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */