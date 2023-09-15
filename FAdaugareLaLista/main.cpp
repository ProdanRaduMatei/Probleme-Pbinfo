void adaugare (nod *&p,int x) {
    nod *q,*t;
    if (p==NULL) {
        p=new nod;
        p->info=x;
        p->urm=0;
    }
    else {
        for (q=p;q->urm!=0;q=q->urm);
        t=new nod;
        t->info=x;
        t->urm=0;
        q->urm=t;
    }
}
