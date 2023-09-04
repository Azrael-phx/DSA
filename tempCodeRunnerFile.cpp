vector<vector<int>>ans;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]+arr[j] == k)
                ans.push_back({arr[i], arr[j]});
        }
    }
    return ans;