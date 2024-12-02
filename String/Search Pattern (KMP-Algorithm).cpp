int pos = 0;
        vector<int> ans;
        
        while(1) {
            size_t ind = txt.find(pat,pos);
            if(ind != std::string::npos) {
                ans.push_back(ind);
                pos = ind+1;
            }
            else {
                break;
            }
        }
        
        return ans;
