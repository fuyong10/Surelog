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
 * File:   Builtin.h
 * Author: alain
 *
 * Created on May 30, 2019, 6:36 PM
 */

#ifndef BUILTIN_H
#define BUILTIN_H

namespace SURELOG {

class Design;

class Builtin {
 public:
  Builtin(Design* design) : m_design(design) {}

  void addBuiltins();

  virtual ~Builtin();

 private:
  Design* m_design;
};

};  // namespace SURELOG

#endif /* BUILTIN_H */
