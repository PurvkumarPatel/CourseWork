#include<bits/stdc++.h>
using namespace std;
int lpageFaults=0;
void lru(int numPages, int numFrames, int pages[]) {
    
    int frames[numFrames], age[numFrames];
    memset(frames,-1,sizeof(frames));
    memset(age,-1,sizeof(age));
    cout<<"\nLRU:\npage no.\tpage frames\n";
    for(int i=0;i<numPages;i++){
        bool found=false;
        int minAge=INT_MAX, index=0;
        for(int j=0;j<numFrames;j++){
            if(frames[j]==pages[i]){
                found=true;
                break;
            }
            if(age[j]<minAge){
                minAge=age[j];
                index=j;
            }
        }
        if(!found){
            frames[index]=pages[i];
            age[index]=i;
            lpageFaults++;
        } else {
            age[distance(frames,find(frames,frames+numFrames,pages[i]))]=i;
        }
        cout<<pages[i]<<"\t\t";
        for(int j=0;j<numFrames;j++){
            if(frames[j]==-1){
                cout<<"-\t";
            } else {
                cout<<frames[j]<<"\t";
            }
        }
        cout<<endl;
    }
    cout<<"\nTotal page fault is "<<lpageFaults<<endl;
}

int main(){
    
    int numPages, numFrames, pageFaults;
    cout<<"Enter number of Pages: ";
    cin>>numPages;
    int pages[numPages];
    cout<<"Enter the Page numbers: ";
    for(int i=0;i<numPages;i++){
        cin>>pages[i];
    }
    cout<<"Enter number of Frames: ";
    cin>>numFrames;
    int frames[numFrames];
    memset(frames,-1,sizeof(frames));
    cout<<"\nFCFS:\npage no.\tpage frames\n";
    pageFaults=0;
    for(int i=0;i<numPages;i++){
        bool found=false;
        for(int j=0;j<numFrames;j++){
            if(frames[j]==pages[i]){
                found=true;
                break;
            }
        }
        if(!found){
            frames[pageFaults%numFrames]=pages[i];
            pageFaults++;
        }
        cout<<pages[i]<<"\t\t";
        for(int j=0;j<numFrames;j++){
            if(frames[j]==-1){
                cout<<"-\t";
            } else {
                cout<<frames[j]<<"\t";
            }
        }
        cout<<endl;
    }
    cout<<"\nTotal page fault is "<<pageFaults<<endl;
    lru(numPages, numFrames, pages);
    if(pageFaults==lpageFaults){
        cout<<"\nBoth algorithms have same page faults.\n";
    } else if(pageFaults>lpageFaults){
        cout<<"\nLRU is better with "<<lpageFaults<<" page faults.\n";
    } else {
        cout<<"\nFCFS is better with "<<pageFaults<<" page faults.\n";
    }
    return 0;
}
