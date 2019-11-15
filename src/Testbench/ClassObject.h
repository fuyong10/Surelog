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
 * File:   ClassObject.h
 * Author: alain
 *
 * Created on March 24, 2019, 7:38 PM
 */

#ifndef CLASSOBJECT_H
#define CLASSOBJECT_H

#include "ClassDefinition.h"
#include "../Expression/Value.h"

namespace SURELOG {

class ClassObject {
 public:
  ClassObject(ClassDefinition* class_def) : m_class(class_def) {}
  ClassObject(const ClassObject& orig);
  virtual ~ClassObject();
  ClassDefinition* getClass() { return m_class; }

  typedef std::map<std::string, std::pair<Property*, Value*>> PropertyValueMap;

  PropertyValueMap& getProperties() { return m_properties; }

  bool setValue(std::string& property, Value* value);

  Value* getValue(std::string& property);

 private:
  ClassDefinition* m_class;
  PropertyValueMap m_properties;
};

};  // namespace SURELOG

#endif /* CLASSOBJECT_H */