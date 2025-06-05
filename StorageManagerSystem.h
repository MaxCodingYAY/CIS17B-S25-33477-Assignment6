// StorageManagerSystem.h
#ifndef STORAGEMANAGERSYSTEM_H
#define STORAGEMANAGERSYSTEM_H

#include <string>
#include <unordered_map>
#include <map>
#include <memory>
#include <stdexcept>
#include <vector>

// Exception for duplicate items, thrown when trying to add item with same id
class DuplicateItemException : public std::runtime_error {
public:
    DuplicateItemException(const std::string& msg) : std::runtime_error(msg) {}
};

// Exception for items not found
class ItemNotFoundException : public std::runtime_error {
public:
    ItemNotFoundException(const std::string& msg) : std::runtime_error(msg) {}
};

// Represents an item being stored
class StoredItem {
private:
    std::string id;
    std::string description;
    std::string location;

public:
    //Constructor
    StoredItem(std::string id, std::string desc, std::string loc)
        : id(std::move(id)), description(std::move(desc)), location(std::move(loc)) {}
    //get id, description, location
    std::string getId() const { return id; }
    std::string getDescription() const { return description; }
    std::string getLocation() const { return location; }
};

// StorageManager class
class StorageManager {

//map to loopup items by unique ID
private:
    std::unordered_map<std::string, std::shared_ptr<StoredItem>> itemById;
    std::multimap<std::string, std::shared_ptr<StoredItem>> itemByDescription;

//multimap for storing multiple items with similar description
public:
    void addItem(const std::shared_ptr<StoredItem>& item) {
        if (itemById.count(item->getId()) > 0) {
            throw DuplicateItemException("Item with ID " + item->getId() + " already exists.");
        }
        itemById[item->getId()] = item;
        itemByDescription.insert({item->getDescription(), item});
    }

    std::shared_ptr<StoredItem> findById(const std::string& id) const {
        auto it = itemById.find(id);
        if (it == itemById.end()) {
            throw ItemNotFoundException("Item with ID " + id + " not found.");
        }
        return it->second;
    }
//removes item by ID
    void removeItem(const std::string& id) {
        // Check if item exists by ID
        auto it = itemById.find(id);
        if (it == itemById.end()) {
            throw ItemNotFoundException("Item with ID " + id + " not found.");
        }

        // Get the description of the item to narrow down in multimap
        std::string desc = it->second->getDescription();

        // Remove from unordered map (by ID)
        itemById.erase(it);

        // Remove only the entry in multimap that matches both description AND ID
        auto range = itemByDescription.equal_range(desc);
        for (auto itr = range.first; itr != range.second; ++itr) {
            if (itr->second->getId() == id) {
                itemByDescription.erase(itr);  // Only erase the one with matching ID
                break;
            }
        }
    }

    // returns lists of stored items, sorted by description alphabetically
    std::vector<std::shared_ptr<StoredItem>> listItemsByDescription() const {
        std::vector<std::shared_ptr<StoredItem>> items;
        // loop through map to store items by descripition
        for (const auto& pair : itemByDescription) {
            items.push_back(pair.second); //add each shared_ptr to vector
        }

        //return the list of items
        return items;
    }
};

#endif // STORAGEMANAGERSYSTEM_H
