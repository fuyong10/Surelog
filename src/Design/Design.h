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
 * File:   Design.h
 * Author: alain
 *
 * Created on July 1, 2017, 1:23 PM
 */

#ifndef DESIGN_H
#define DESIGN_H
#include "Design/ModuleDefinition.h"
#include "Design/ModuleInstance.h"
#include "Design/DefParam.h"
#include "Library/LibrarySet.h"
#include "Config/ConfigSet.h"
#include "Package/Package.h"
#include "Testbench/Program.h"

namespace SURELOG {

class Design {
 friend class CompileDesign;
 friend class AnalyzeFile; 
 friend class PreprocessFile;
 friend class ParseFile;
 friend class Compiler;
 friend class PPCache;
 friend class ParseCache;
 friend class SV3_1aPpTreeShapeListener;
 friend class SV3_1aTreeShapeListener;
 friend class Builtin;
 friend class DesignElaboration;
 friend class SVLibShapeListener;
 public:
     
  Design(ErrorContainer* errors, LibrarySet* librarySet, ConfigSet* configSet)
      : m_errors(errors),
        m_librarySet(librarySet),
        m_configSet(configSet) {}
      
  Design(const Design& orig);
  
  virtual ~Design();

  typedef std::vector<std::pair<SymbolId, FileContent*>> FileIdDesignContentMap;

  FileIdDesignContentMap& getAllFileContents() { return m_fileContents; }
  
  FileIdDesignContentMap& getAllPPFileContents() { return m_ppFileContents; }
  
  LibrarySet* getLibrarySet() { return m_librarySet; }
  
  ConfigSet* getConfigSet() { return m_configSet; }

  ModuleNameModuleDefinitionMap& getModuleDefinitions() {
    return m_moduleDefinitions;
  }
  
  PackageNamePackageDefinitionMultiMap& getPackageDefinitions() {
    return m_packageDefinitions;
  }
  
  PackageDefinitionVec& getOrderedPackageDefinitions() {
    return m_orderedPackageDefinitions;
  }
  
  ProgramNameProgramDefinitionMap& getProgramDefinitions() {
    return m_programDefinitions;
  }
  
  ClassNameClassDefinitionMultiMap& getClassDefinitions() {
    return m_classDefinitions;
  }
  
  ClassNameClassDefinitionMap& getUniqueClassDefinitions() {
    return m_uniqueClassDefinitions;
  }

  ModuleDefinition* getModuleDefinition(const std::string& moduleName);

  DesignComponent* getComponentDefinition(const std::string& componentName);

  std::vector<ModuleInstance*>& getTopLevelModuleInstances() {
    return m_topLevelModuleInstances;
  }

  std::string reportInstanceTree();

  void reportInstanceTreeStats(unsigned int& nbTopLevelModules,
                               unsigned int& maxDepth,
                               unsigned int& numberOfInstances,
                               unsigned int& numberOfLeafInstances,
                               unsigned int& nbUndefinedModules,
                               unsigned int& nbUndefinedInstances);
  
  DefParam* getDefParam(std::string name);
  
  Value* getDefParamValue(std::string name);
  
  std::map<std::string, DefParam*>& getDefParams() { return m_defParams; }
  
  void checkDefParamUsage(DefParam* parent = NULL);

  ModuleInstance* findInstance(std::vector<std::string>& path,
                               ModuleInstance* scope = NULL);
  
  ModuleInstance* findInstance(std::string path, ModuleInstance* scope = NULL);
  
  Package* getPackage(std::string name);

  Program* getProgram(std::string name);
  
  ClassDefinition* getClassDefinition(std::string name);

  ErrorContainer* getErrorContainer() { return m_errors; }
  
 protected:
   
  // Thread-safe
  void addFileContent(SymbolId fileId, FileContent* content);
  
  // Thread-safe
  void addPPFileContent(SymbolId fileId, FileContent* content);
  
  void addOrderedPackage(std::string packageName) {
    m_orderedPackageNames.push_back(packageName);
  }   
     
  void addModuleDefinition(std::string moduleName, ModuleDefinition* def) {
    m_moduleDefinitions.insert(std::make_pair(moduleName, def));
  }   
     
  void addTopLevelModuleInstance(ModuleInstance* instance) {
    m_topLevelModuleInstances.push_back(instance);
  }   
  
  void addDefParam(std::string name, FileContent* fC, NodeId nodeId,
                   Value* value);  
     
  void addClassDefinition(std::string className, ClassDefinition* classDef);

  void addProgramDefinition(std::string programName, Program* program) {
    m_programDefinitions.insert(std::make_pair(programName, program));
  }  
     
  Package* addPackageDefinition(std::string packageName, Package* package);
    
  void clearContainers();
  
  void orderPackages();
  
 private:
  ModuleInstance* findInstance_(std::vector<std::string>& path,
                                ModuleInstance* scope);
  void addDefParam_(std::vector<std::string>& path, FileContent* fC,
                    NodeId nodeId, Value* value, DefParam* parent);
  DefParam* getDefParam_(std::vector<std::string>& path, DefParam* parent);

  ErrorContainer* m_errors;
  
  LibrarySet* m_librarySet;
  
  ConfigSet* m_configSet;
  
  FileIdDesignContentMap m_fileContents;
  
  FileIdDesignContentMap m_ppFileContents;
  
  ModuleNameModuleDefinitionMap m_moduleDefinitions;

  std::vector<ModuleInstance*> m_topLevelModuleInstances;

  std::map<std::string, DefParam*> m_defParams;

  PackageNamePackageDefinitionMultiMap m_packageDefinitions;
  
  PackageDefinitionVec m_orderedPackageDefinitions;

  ProgramNameProgramDefinitionMap m_programDefinitions;

  ClassNameClassDefinitionMultiMap m_classDefinitions;

  ClassNameClassDefinitionMap m_uniqueClassDefinitions;

  std::vector<std::string> m_orderedPackageNames;
};

};  // namespace SURELOG

#endif /* DESIGN_H */
