/*
 Copyright 2019 Alain Dargelas

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

/*
 * File:   DefParam.h
 * Author: alain
 *
 * Created on January 7, 2018, 8:54 PM
 */

#ifndef DEFPARAM_H
#define DEFPARAM_H
#include "Expression/Value.h"
#include <map>

namespace SURELOG {

class DefParam {
 public:
  DefParam(std::string name, DefParam* parent = NULL)
      : m_name(name),
        m_value(NULL),
        m_used(false),
        m_parent(parent),
        m_fileContent(NULL),
        m_nodeId(0) {}

  DefParam(const DefParam& orig);

  virtual ~DefParam();

  Value* getValue() { return m_value; }
  void setValue(Value* value) { m_value = value; }

  void setChild(std::string name, DefParam* child) {
    m_children.insert(std::make_pair(name, child));
  }
  std::map<std::string, DefParam*>& getChildren() { return m_children; }
  bool isUsed() { return m_used; }
  void setUsed() { m_used = true; }
  void setLocation(FileContent* fC, NodeId nodeId) {
    m_fileContent = fC;
    m_nodeId = nodeId;
  }
  FileContent* getLocation() { return m_fileContent; }
  NodeId getNodeId() { return m_nodeId; }
  std::string getFullName();
  DefParam* getParent() { return m_parent; }

 private:
  std::string m_name;
  std::map<std::string, DefParam*> m_children;
  Value* m_value;
  bool m_used;
  DefParam* m_parent;
  FileContent* m_fileContent;
  NodeId m_nodeId;
};

};  // namespace SURELOG

#endif /* DEFPARAM_H */
