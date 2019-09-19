#pragma once

// This is data that every object should have and should be unique for every instantiation
class MetaData {
public:
  MetaData(int id) : id_(id) {}

  int getID() { return id_; }

private:
  int id_;
};
