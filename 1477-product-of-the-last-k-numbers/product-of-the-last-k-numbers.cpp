class ProductOfNumbers {
public:
    vector<int>temp;
    ProductOfNumbers() {
        temp.push_back(-1);
    }

    void add(int num) {
       temp.push_back(num);
    }
    
    int getProduct(int k) {
       int n=temp.size();
       int ans=1;
       for(int i=n-1;i>=n-k;i--){
         if(temp[i]!=-1)
         ans=ans*temp[i];
       }
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */