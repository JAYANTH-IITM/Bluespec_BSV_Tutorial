/*
 * Generated by Bluespec Compiler, version 2024.07 (build b4f31db)
 * 
 * On Fri Oct 18 20:39:10 IST 2024
 * 
 */
#include "bluesim_primitives.h"
#include "model_mkTestbench.h"

#include <cstdlib>
#include <time.h>
#include "bluesim_kernel_api.h"
#include "bs_vcd.h"
#include "bs_reset.h"


/* Constructor */
MODEL_mkTestbench::MODEL_mkTestbench()
{
  mkTestbench_instance = NULL;
}

/* Function for creating a new model */
void * new_MODEL_mkTestbench()
{
  MODEL_mkTestbench *model = new MODEL_mkTestbench();
  return (void *)(model);
}

/* Schedule functions */

static void schedule_posedge_CLK(tSimStateHdl simHdl, void *instance_ptr)
       {
	 MOD_mkTestbench &INST_top = *((MOD_mkTestbench *)(instance_ptr));
	 INST_top.DEF_CAN_FIRE_RL_retint = (tUInt8)1u;
	 INST_top.DEF_WILL_FIRE_RL_retint = INST_top.DEF_CAN_FIRE_RL_retint;
	 if (INST_top.DEF_WILL_FIRE_RL_retint)
	   INST_top.RL_retint();
	 if (do_reset_ticks(simHdl))
	 {
	 }
       };

/* Model creation/destruction functions */

void MODEL_mkTestbench::create_model(tSimStateHdl simHdl, bool master)
{
  sim_hdl = simHdl;
  init_reset_request_counters(sim_hdl);
  mkTestbench_instance = new MOD_mkTestbench(sim_hdl, "top", NULL);
  bk_get_or_define_clock(sim_hdl, "CLK");
  if (master)
  {
    bk_alter_clock(sim_hdl, bk_get_clock_by_name(sim_hdl, "CLK"), CLK_LOW, false, 0llu, 5llu, 5llu);
    bk_use_default_reset(sim_hdl);
  }
  bk_set_clock_event_fn(sim_hdl,
			bk_get_clock_by_name(sim_hdl, "CLK"),
			schedule_posedge_CLK,
			NULL,
			(tEdgeDirection)(POSEDGE));
  (mkTestbench_instance->set_clk_0)("CLK");
}
void MODEL_mkTestbench::destroy_model()
{
  delete mkTestbench_instance;
  mkTestbench_instance = NULL;
}
void MODEL_mkTestbench::reset_model(bool asserted)
{
  (mkTestbench_instance->reset_RST_N)(asserted ? (tUInt8)0u : (tUInt8)1u);
}
void * MODEL_mkTestbench::get_instance()
{
  return mkTestbench_instance;
}

/* Fill in version numbers */
void MODEL_mkTestbench::get_version(char const **name, char const **build)
{
  *name = "2024.07";
  *build = "b4f31db";
}

/* Get the model creation time */
time_t MODEL_mkTestbench::get_creation_time()
{
  
  /* Fri Oct 18 15:09:10 UTC 2024 */
  return 1729264150llu;
}

/* State dumping function */
void MODEL_mkTestbench::dump_state()
{
  (mkTestbench_instance->dump_state)(0u);
}

/* VCD dumping functions */
MOD_mkTestbench & mkTestbench_backing(tSimStateHdl simHdl)
{
  static MOD_mkTestbench *instance = NULL;
  if (instance == NULL)
  {
    vcd_set_backing_instance(simHdl, true);
    instance = new MOD_mkTestbench(simHdl, "top", NULL);
    vcd_set_backing_instance(simHdl, false);
  }
  return *instance;
}
void MODEL_mkTestbench::dump_VCD_defs()
{
  (mkTestbench_instance->dump_VCD_defs)(vcd_depth(sim_hdl));
}
void MODEL_mkTestbench::dump_VCD(tVCDDumpType dt)
{
  (mkTestbench_instance->dump_VCD)(dt, vcd_depth(sim_hdl), mkTestbench_backing(sim_hdl));
}
