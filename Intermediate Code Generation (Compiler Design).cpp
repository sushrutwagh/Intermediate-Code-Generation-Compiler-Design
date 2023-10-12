#include <bits/stdc++.h>
using namespace std;

// vector keeping the count of operators in order of their precedence.v[0] is the highest precedence one.
//vector is getting new updated string as an input and outputting the iterator positions and preference nos of the operators present in the string
vector<pair<int,int>> updatevec(string s){
    vector<pair<int,int>>ans;
    for(int i=0;i<s.size();i++){
        if(s[i]=='%'){
            //assigning value 1 to the / operator so that after sorting the vector in ascending order, we get / at v[0]
            // same for other 3 operators
            ans.push_back({1,i});
        }
        else if(s[i]=='/'){
            ans.push_back({2,i});
        }
        else if(s[i]=='*'){
            ans.push_back({3,i});
        }
        else if(s[i]=='+'){
            ans.push_back({4,i});
        }
        else if(s[i]=='-'){
            ans.push_back({5,i});
        }
    }
    //sorting the vector of pairs in ascending order so that the highest precedence operator i.e. the one having the lowest value comes at index 0 i.e. v[0] of the vector
    sort(ans.begin(),ans.end());

    // for(auto it:ans){
    //  cout<<it.first<<" "<<it.second<<endl;
    // }
    // cout<<endl<<endl;
    return ans;
}




int main()
{
    string s;
    cout<<"Enter the Expression : ";
    cin>>s;
    int check = 0;
    // small letters are in input symbols and capital letters are the temporary variables

    // has precedence 1, * has 2 and so on and well sort the vector in ascending order on each iteration so that we get the highest precedence one first
    vector<pair<int,int>>v;
    v = updatevec(s);

    //vector to save all the newly created teporary variables
    vector<char>tempvariables;
    char temptoadd = 'Z';
    while(v.size()!=0 && s.size()>3){
        string temp = "";
        //adding the operand on the left side of operator having the highest precedence in the current string
        temp.push_back(s[v[0].second - 1]);
        //adding the  operator having the highest precedence in the current string
        if(v[0].first==1){
            temp.push_back('%');
        }
        else if(v[0].first==2){
            temp.push_back('/');
        }
        else if(v[0].first==3){
            temp.push_back('*');
        }
        else if(v[0].first==4){
            temp.push_back('+');
        }
        else{
            temp.push_back('-');
        }
        //adding the operand on the left side of operator having the highest precedence in the current string
        temp.push_back(s[v[0].second + 1]);
        string temporary = "";
        temporary.push_back(temptoadd);
        temporary = temporary  + "=" + temp;
        //printing one relation/result of a newly created tempporary variable
        cout<<temporary<<"\t\t";

        string str = "";
        //copying the characters on the left side of the left operand of the string
        for(int i=0;i<v[0].second-1;i++){
            str.push_back(s[i]);
        }
        //adding the newly created temporary variable to the string
        str.push_back(temptoadd);
        //copying the remaining i.e. the part to the right side of the right operand of the string
        for(int i=v[0].second+2;i<s.size();i++){
            str.push_back(s[i]);
            // cout<<s[i]<<" ";
        }
        //updating the original string with the newly formed string having the new temporary variables
        s = str;
        cout<<s<<endl;
        //updating the vector after the original string has been updated
        v = updatevec(s);
        //adding all temporary variables that have been created to a vector so that we can print it at the end to let the user know what all temporary variables had been created.
        tempvariables.push_back(temptoadd);
        temptoadd--;
    }
    //printing all the temporary variables that had been created
    cout<<endl<<"The following are the temporary variables that were created : ";
    for(auto it:tempvariables){
        cout<<it<<" ";
    }


    return 0;
}
