struct Set {
    Set *parent;
    int rank;
    // can include a mergable data like
    // int data;
};
Set *CreateSet() {  // create a singleton set
    Set *s = new Set();
    s->parent = s;
    s->rank = 0;
    // initialize the data value here
    return s;
}
Set *GetSet(Set *set) {  // get the parent set of the element
    if (set->parent != set) {
        set->parent = GetSet(set->parent);
        return set->parent;
    } else {
        return set;
    }
}
bool SameSet(Set *set1, Set *set2) {  // use this function to check if two
                                      // elements belong to same set
    return GetSet(set1) == GetSet(set2);
}
void SetUnion(Set *set1, Set *set2) {  // unify two disjoint set
    Set *pset1 = GetSet(set1);
    Set *pset2 = GetSet(set2);
    if (pset1 != pset2) {
        Set *pset = nullptr;
        if (pset1->rank > pset2->rank) {
            pset2->parent = pset1;
            pset = pset1;
        } else if (pset1->rank < pset2->rank) {
            pset1->parent = pset2;
            pset = pset2;
        } else {
            pset1->parent = pset2;
            pset2->rank++;
            pset = pset2;
        }
        // merge the data values for pset1 and pset2 for pset
    }
}
int main() {
    Set *a = CreateSet();  // use Create set to creat a new disjoint set
    Set *b = CreateSet();
    SameSet(a, b);   // initially will return false
    SetUnion(a, b);  // for set union of a,b
    SameSet(a, b);   // finally will return true
}