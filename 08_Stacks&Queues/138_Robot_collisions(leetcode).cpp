class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        vector<int> actual_idx(n);

        for (int i=0;i<n;i++){ // store 0,1,2,3...n-1 in actual indx to get started;
            actual_idx[i]=i;

        }
        // make a lambda function
        auto lambda=[&](int &i, int &j){ 
            return positions[i] < positions[j];
        };
        sort(begin(actual_idx), end(actual_idx), lambda); // sort according to how it appears  in number line-> we are sorting so that via indx we can go to healths and directions

        vector<int> res;
        stack<int> st;

        for (int curr_idx: actual_idx){
            if (directions[curr_idx]=='R'){
                st.push(curr_idx); // move forward and store in stack the curr_idx value(acc to number line)

            }
            else{ // means dirn is left
                while(!st.empty() && healths[curr_idx]>0){
                    int top_idx=st.top(); // get the top elemn from stack
                    st.pop();
                    if (healths[top_idx] > healths[curr_idx]){
                        // it destroys the incoming left robot
                        healths[top_idx]-=1; // one less to health at top
                        healths[curr_idx]=0; // the destroyed goes to 0
                        st.push(top_idx); // pushed on tos the top idx
                    }
                    else if (healths[top_idx] < healths[curr_idx]){
                        // the right one gets destroyed as left has larger health
                        healths[top_idx]=0;
                        healths[curr_idx]-=1;
                        
                    }
                    else{
                        // if same health:
                        healths[curr_idx]=0;
                        healths[top_idx]=0;
                    }

                }
            }
        }
        for (int i=0;i<n;i++){
            if (healths[i]>0){
                res.push_back(healths[i]);
            }
        }
        return res;



        
    }
};