#pragma once

#include "utils/Block.hh"
#include "utils/Logger.hh"
#include "utils/UtilityBlocks.hh"
#include <vector>


class API
{
public:

  API();
  ~API();

  template<typename T>
  DataPromise<T>& input()
  {
    auto ret = new Input<T>();
    blocks.push_back(ret);
    return ret->out;
  }

  template<typename T>
  Output<T>& output(DataPromise<T>& src)
  {
    auto ret = new Output<T>();
    ret->in.connect(src);
    blocks.push_back(ret);
    return *ret;
  }

public:

  Logger logger;

protected:

  std::vector<Block*> blocks;
};
