/******************************************************************************
 * (C) Copyright 2015 AMIQ Consulting
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * NAME:        amiq_svaunit_ex_basic_pkg.sv
 * PROJECT:     svaunit
 * Description: Package with a simple example of SVAUnit tests
 *******************************************************************************/

`ifndef AMIQ_SVAUNIT_EX_BASIC_PKG_SV
`define AMIQ_SVAUNIT_EX_BASIC_PKG_SV

`include "basic_interface.sv"

package amiq_svaunit_ex_basic_pkg;
	import svaunit_pkg::*;
	import uvm_pkg::*;
	`include "uvm_macros.svh"
	
	`include "amiq_svaunit_ex_basic_test.sv"

endpackage

`endif
