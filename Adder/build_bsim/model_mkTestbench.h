/*
 * Generated by Bluespec Compiler, version 2024.07 (build b4f31db)
 * 
 * On Fri Oct 18 20:39:10 IST 2024
 * 
 */

/* Generation options: keep-fires */
#ifndef __model_mkTestbench_h__
#define __model_mkTestbench_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"

#include "bs_model.h"
#include "mkTestbench.h"

/* Class declaration for a model of mkTestbench */
class MODEL_mkTestbench : public Model {
 
 /* Top-level module instance */
 private:
  MOD_mkTestbench *mkTestbench_instance;
 
 /* Handle to the simulation kernel */
 private:
  tSimStateHdl sim_hdl;
 
 /* Constructor */
 public:
  MODEL_mkTestbench();
 
 /* Functions required by the kernel */
 public:
  void create_model(tSimStateHdl simHdl, bool master);
  void destroy_model();
  void reset_model(bool asserted);
  void get_version(char const **name, char const **build);
  time_t get_creation_time();
  void * get_instance();
  void dump_state();
  void dump_VCD_defs();
  void dump_VCD(tVCDDumpType dt);
};

/* Function for creating a new model */
extern "C" {
  void * new_MODEL_mkTestbench();
}

#endif /* ifndef __model_mkTestbench_h__ */
