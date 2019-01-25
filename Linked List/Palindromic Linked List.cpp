int check(listnode **head, listnode *curr){
    int a = 1;
    if(!curr);
    else{
        a =check(head, curr->next);
        if((*head)->val != curr->val){*head = (*head)->next; return 0;}
        *head = (*head)->next;
    }
    return a;
    
 }
int lPalin(listnode* A) {
    return check(&A,A);
}