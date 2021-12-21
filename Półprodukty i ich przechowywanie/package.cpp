    //
    // Created by Acer on 19.12.2021.
    //

    #include "package.hpp"

    Package::Package() {
        ElementID newId = 1;

        while(true){
            if(Package::freed_ids.find(newId) != Package::freed_ids.end()){
                Package::freed_ids.erase(newId);
                Package::assigned_ids.insert(newId);
                this->id= newId;
                break;
            }
            else if(Package::assigned_ids.find(newId) == Package::assigned_ids.end()){
                Package::assigned_ids.insert(newId);
                this->id= newId;
                break;
            }else{
                newId++;
            }
        }
    }

    Package::Package(ElementID id): id(id) {

    }

    Package::Package(Package const & other) noexcept : id(other.id) {

    }

    Package &Package::operator=(Package const& other) noexcept{
        this->id = other.id;
        return *this;
    }

    ElementID Package::get_id() const {
        return this->id;
    }

    Package::~Package() {
        Package::assigned_ids.erase(this->id);
        Package::freed_ids.insert(this->id);
    }

