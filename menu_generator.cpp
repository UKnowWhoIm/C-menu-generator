#include<iostream>
#include<string>
#include<vector>

using namespace std;

const int defaultIntentLevel = 1;

string getIntent(int intent=defaultIntentLevel){
    string a;
    for(int i=0; i<intent; i++)
        a += '\t';
    return a;
}

const string dispFunctionName = "dispMenu()";

const string choiceVariable = "choice";

const string exitChoice = "-1";

const string loopBegin = getIntent() + "int " + choiceVariable + ";\n" + getIntent() + "do{\n"  + getIntent(defaultIntentLevel+1)
                        + dispFunctionName + ";\n" + getIntent(defaultIntentLevel+1) + "scanf(\"%d\", &" + choiceVariable + ");"
                        + "\n" + getIntent(defaultIntentLevel + 1) + "switch(choice){";

const string loopEnd = getIntent(defaultIntentLevel + 1) + "}\n" + getIntent() + "}while(" + choiceVariable + " != \'" + exitChoice + "\');";

string generateCase(int caseNum, string callback){
    return getIntent(defaultIntentLevel+2) + "case " + to_string(caseNum) + ": " + callback + ";break;";
}

string generateLoopBody(vector<string> data,int beginNum=0){
    string body = loopBegin;
    int j=beginNum;
    for(auto i = data.begin(); i != data.end(); i++, j++){
        body += "\n" + generateCase(j, *i);
    }
    body += "\n" + loopEnd;
    return body;
}

int main(){
    vector<string> data;
    string temp;
    do{
        cin>>temp;
        if(temp != "-1")
            data.push_back(temp);
    }while(temp != "-1");
    cout<<generateLoopBody(data);

    return 0;
}
