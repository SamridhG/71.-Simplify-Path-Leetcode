class Solution {
public:
    string simplifyPath(string s) {
	vector<string>A;
	string p="";
	if(s[s.size()-1]!='/'){ s=s+'/';}    // making last character '/'
	for(int i=0;i<s.size();i++)  // scanning 
	{ 
	if(s[i+1]=='/' && i+1<s.size()) // when next '/' comes
	{
		p=p+s[i];  
		A.push_back(p);
		p.clear();
        if(A.back()=="/"){A.pop_back();}
        else if(A.back()=="/."){A.pop_back();}
        else if(A.back()=="/..")
        {
            A.pop_back();
            if(!A.empty())
            {
                A.pop_back();
            }
        }
		
	}
	else{  // '/' didt come
		p=p+s[i];
	}
	}
		if(A.empty()){A.push_back("/");}     // check wheater stack didnt empty 
     
        p.clear();
        for(int i=0;i<A.size();i++)
        {
            p=p+A[i];
        }
        cout<<p;
        return p;
    }
};
