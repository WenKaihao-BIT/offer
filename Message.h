//
// Created by Q on 2023/3/6.
//

#ifndef OFFER_MESSAGE_H
#define OFFER_MESSAGE_H
#include "iostream"
#include "string"
#include <set>
class Message;
class Folder{
public:
    void addMsg(Message*);
    void remMsg(Message*);
private:
    std::set<Message*>Messages;

};

void Folder::addMsg(Message *M) {
    Folder::Messages.insert(M);
}

void Folder::remMsg(Message *M) {
    Messages.erase(M);
}
class Message{
    friend class Folder;
    friend void swap(Message &lhs,Message &rhs);
public:
    explicit Message(const std::string &str = ""):contents(str) {}
    Message(const Message&);
    Message & operator=(const Message &);
    ~Message();
    void save(Folder&);
    void remove(Folder&);
private:
    std::string contents;
    std::set<Folder*>folders;
    void add_to_Folders(const Message&);
    void remove_from_Folders();
};
void Message::save(Folder &f) {
    folders.insert(&f);
    f.addMsg(this);
}
void Message::remove(Folder &f) {
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message &M) {
    for(auto f:M.folders)
        f->addMsg(this);
}
Message::Message(const Message &M) :
        contents(M.contents),folders(M.folders){
    add_to_Folders(M);
}

void Message::remove_from_Folders() {
    for(auto f:folders)
        f->remMsg(this);
}
Message::~Message() {
    remove_from_Folders();
}

Message &Message::operator=(const Message &rhs) {
    remove_from_Folders();
    contents=rhs.contents;
    folders=rhs.folders;
    add_to_Folders(rhs);
}
void swap(Message &lhs,Message &rhs){
    using std::swap;
    for(auto f:lhs.folders)
        f->remMsg(&lhs);
    for(auto f:rhs.folders)
        f->remMsg(&rhs);
    swap(lhs.folders,rhs.folders);
    swap(lhs.contents,rhs.contents);
    for(auto f:lhs.folders)
        f->addMsg(&lhs);
    for(auto f:rhs.folders)
        f->addMsg(&rhs);
}
#endif //OFFER_MESSAGE_H
