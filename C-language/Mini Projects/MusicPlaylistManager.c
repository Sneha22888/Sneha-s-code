/*Music Playlist Manager(add,delete,search,play next,play previous,count total,insert)song,
(display,shuffle,save,load)playlist*/ 
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
struct Music{
    char name[50];
    struct Music *next;
    struct Music *prev;
};
struct Music *head=NULL;
struct Music *tail=NULL;
struct Music *current=NULL;
//Insert Music in playlist
void InsertMusic(){
    struct Music *newnode;
    int choice;
    newnode=(struct Music*)malloc(sizeof(struct Music));
    printf("Enter song name : ");
    scanf(" %49[^\n]",newnode->name);
    newnode->next=NULL;
    newnode->prev=NULL;
    printf("Where do you want to insert : \n");
    printf("1. Beginning\n");
    printf("2. nth position\n");
    printf("3. End\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);
    switch(choice){
        case 1:  //beginning
            if(head==NULL){
                head=newnode;
                tail=newnode;
            }
            else{
                newnode->next=head;
                newnode->prev=NULL;
                head=newnode;
            }
            printf("Song inserted at beginning.\n");
            break;
        case 2:  //nth position
        {
            int position;
            struct Music *temp;
            printf("Enter the position you want to add new music : ");
            scanf("%d",&position);
            if(position==1){
                newnode->next=head;
                if(head!=NULL)
                    head->prev=newnode;
                head=newnode;
                if(tail==NULL)
                    tail=newnode;
            }
            else{
                temp=head;
                for(int i=0;i<position-2 && temp!=NULL;i++){
                    temp=temp->next;
                }
                if(temp==NULL){
                    printf("Invalid position!\n");
                    free(newnode);
                }
                else{
                    newnode->next=temp->next;
                    newnode->prev=temp;
                    if(temp->next!=NULL)
                        temp->next->prev=newnode;
                    else
                        tail=newnode;
                    temp->next=newnode;
                    printf("Song inserted successfully.\n");
                }
            }
            break;
        }
        case 3:  //end
            if(head==NULL){
                head=newnode;
                tail=newnode;
            }
            else{
                tail->next=newnode;
                newnode->prev=tail;
                newnode->next=NULL;
                tail=newnode;
            }
            printf("Song inserted at end.\n");
            break;
        default:
            printf("Invalid position.\n");
    }
    if(current==NULL){
        current=newnode;
    }
}
//Display playlist
void DisplayPlaylist(){
    struct Music *temp;
    if(head==NULL){
        printf("Playlist is empty.\n");
    }
    temp=head;
    printf("Music List is : \n");
    while(temp!=NULL){
        printf("%s -> ",temp->name);
        temp=temp->next;
    }
    printf("NULL\n");
}
//Search music from playlist
void SearchMusic(){
    char songname[50];
    struct Music *temp;
    int found=0;
    if(head==NULL){
        printf("Playlist is empty.\n");
    }
    printf("Enter the music you want to search : ");
    scanf(" %[^\n]",songname);
    temp=head;
    while(temp!=NULL){
        if(strcmp(temp->name,songname)==0){
            found=1;
            break;
        }
        temp=temp->next;
    }
    if(found)
        printf("Song found in playlist.\n");
    else
        printf("Song not found.\n");
}
//Delete music from playlist
void DeleteMusic(){
    char songname[50];
    int choice;
    struct Music *temp, *temp1;
    printf("Which position do you want to delete : \n");
    printf("1. Beginning\n");
    printf("2. nth position\n");
    printf("3. End\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);
    switch(choice){
        case 1: //beginning
            if(head==NULL){
                printf("Playlist is empty.\n");
            }
            else{
                temp=head;
                if(head==tail){
                    head=NULL;
                    tail=NULL;
                }
                else{
                    head=head->next;
                    head->prev=NULL;
                }
                free(temp);
                printf("Song deleted successfully.\n");
            }
            break;
        case 2:  //nth position
        {  
            int position;
            printf("Enter the position you want to delete : ");
            scanf("%d",&position);
            if(head==NULL){
                printf("Playlist is empty.\n");
            }    
            else if(position==1){
                temp=head;
                if(head==tail){
                    head=NULL;
                    tail=NULL;
                }
                else{
                    head=head->next;
                    head->prev=NULL;
                }
                free(temp);
                printf("Song deleted successfully.\n");
            }
            else{
                temp=head;
                for(int i=0;i<position-1 && temp!=NULL;i++){
                    temp=temp->next;
                }
                if(temp==NULL){
                    printf("Invalid position.\n");
                }
                else{
                    if(temp==tail){
                        tail=tail->prev;
                        tail->next=NULL;
                    }
                    else{
                        temp->prev->next=temp->next;
                        temp->next->prev=temp->prev;
                    }
                    free(temp);
                    printf("Song deleted successfully.\n");
                }
            }
            break;
        }
        case 3:  //end
            if(head==NULL){
                printf("Playlist is empty.\n");
            }
            else{
                temp=tail;
                if(head==tail){
                    head=NULL;
                    tail=NULL;
                }
                else{
                    tail=tail->prev;
                    tail->next=NULL;
                }
                free(temp);
                printf("Song deleted successfully.\n");
            }
            break;
        default:
            printf("Invalid choice!\n");    
    }
}
//Play next song of the playlist
void PlayNext(){
    if(current==NULL){
        printf("Playlist is empty.\n");
    }
    else if(current->next==NULL){
        printf("No next song exists.\n");
    }
    else{
        current=current->next;
        printf("Now playing : %s\n",current->name);
    }
}
//Play previous song of the playlist
void PlayPrev(){
    if(current==NULL){
        printf("Playlist is empty.\n");
    }
    else if(current->prev==NULL){
        printf("No previous song exists.\n");
    }
    else{
        current=current->prev;
        printf("Now playing : %s",current->name);
    }
}
//Count songs in the playlist 
void CountMusic(){
    int count=0;
    struct Music *temp;
    temp=head;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    printf("Total songs : %d\n",count);
}
//Shuffle playlist
void ShufflePlaylist(){
    struct Music *temp;
    struct Music *songs[100];
    int count=0,i,j;
    if(head==NULL){
        printf("Playlist is empty.\n");
    }
    temp=head;
    while(temp!=NULL){
        songs[count++]=temp;
        temp=temp->next;
    }
    srand(time(NULL));
    for(i=count-1;i>0;i--){
        j=rand()%(i+1);
        struct Music *temp1;
        temp1=songs[i];
        songs[i]=songs[j];
        songs[j]=temp1;
    }
    printf("Shuffled playlist : \n");
    for(i=0;i<count;i++){
        printf("%s\n",songs[i]->name);
    }
}
//Save playlist
void SavePlaylist(){
    FILE *fp;
    struct Music *temp;
    fp=fopen("playlist.txt","w");
    if(fp==NULL){
        printf("FILE ERROR!\n");
    } 
    temp=head;
    while(temp!=NULL){
        fprintf(fp,"%s\n",temp->name);
        temp=temp->next;
    }
    fclose(fp);
    printf("Playlist saved successfully.\n");
}
//Load playlist
void LoadPlaylist(){
    FILE *fp;
    char song[50];
    fp=fopen("playlist.txt","r");
    if(fp==NULL){
        printf("No saved playlist found.\n");
    }
    while(fgets(song,sizeof(song),fp)){
        song[strcspn(song,"\n")]='\0';
        struct Music *newnode;
        newnode=(struct Music*)malloc(sizeof(struct Music));
        strcpy(newnode->name,song);
        newnode->next=NULL;
        newnode->prev=NULL;
        if(head==NULL){
            head=tail=newnode;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
    }
    fclose(fp);
    printf("Playlist loaded successfully.\n");
}
int main(){
    int choice;
    do{
        printf("\n\n==========Music Playlist Manager==========\n\n");
        printf("1. Insert song at any position\n");
        printf("2. Display Playlist\n");
        printf("3. Search song\n");
        printf("4. Delete song at any position\n");
        printf("5. Play next song\n");
        printf("6. Play previous song\n");
        printf("7. Count total songs.\n");
        printf("8. Shuffle playlist\n");
        printf("9. Save playlist to file\n");
        printf("10. Load playlist to file\n");
        printf("11. Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                InsertMusic();
                break;
            case 2:
                DisplayPlaylist();
                break;
            case 3:
                SearchMusic();
                break;
            case 4:
                DeleteMusic();
                break;
            case 5:
                PlayNext();
                break;
            case 6:
                PlayPrev();
                break;
            case 7:
                CountMusic();
                break;
            case 8:
                ShufflePlaylist();
                break;
            case 9:
                SavePlaylist();
                break;
            case 10:
                LoadPlaylist();
                break;
            case 11:
                printf("\nThank You\n");
                break;
            default:
                printf("\nInvalid Choice!\n");
        }
    }while(choice!=11);
    return 0;
}