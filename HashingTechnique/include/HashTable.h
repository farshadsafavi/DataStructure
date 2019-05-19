#ifndef HASHTABLE_H
#define HASHTABLE_H


class HashTable
{
    private:
        Node* HT;
        int HashFunction(int key);
    public:
        HashTable();
        HashTable(int Size);
        void HashInsert(int key);
        void Delete(int key);
        bool Search(int key);
        virtual ~HashTable();
};

#endif // HASHTABLE_H
