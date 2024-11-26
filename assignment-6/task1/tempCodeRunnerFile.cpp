
    vector<string> result = longestCommonSubsequence(grades);
    int index = 0;
    for (int i = 0; i < grades.size(); i++)
    {   
        for(int j = i + 1; j<grades.size(); j++){
           cout<<"LCS of the string "<<i+1<<" and "<<j+1<<" is: "<<result[index++]<<endl;
        }
    }