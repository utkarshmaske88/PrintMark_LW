#ifndef __AS__TYPE_
#define __AS__TYPE_
typedef struct {
	unsigned char bit0  : 1;
	unsigned char bit1  : 1;
	unsigned char bit2  : 1;
	unsigned char bit3  : 1;
	unsigned char bit4  : 1;
	unsigned char bit5  : 1;
	unsigned char bit6  : 1;
	unsigned char bit7  : 1;
} _1byte_bit_field_;

typedef struct {
	unsigned short bit0  : 1;
	unsigned short bit1  : 1;
	unsigned short bit2  : 1;
	unsigned short bit3  : 1;
	unsigned short bit4  : 1;
	unsigned short bit5  : 1;
	unsigned short bit6  : 1;
	unsigned short bit7  : 1;
	unsigned short bit8  : 1;
	unsigned short bit9  : 1;
	unsigned short bit10 : 1;
	unsigned short bit11 : 1;
	unsigned short bit12 : 1;
	unsigned short bit13 : 1;
	unsigned short bit14 : 1;
	unsigned short bit15 : 1;
} _2byte_bit_field_;

typedef struct {
	unsigned long bit0  : 1;
	unsigned long bit1  : 1;
	unsigned long bit2  : 1;
	unsigned long bit3  : 1;
	unsigned long bit4  : 1;
	unsigned long bit5  : 1;
	unsigned long bit6  : 1;
	unsigned long bit7  : 1;
	unsigned long bit8  : 1;
	unsigned long bit9  : 1;
	unsigned long bit10 : 1;
	unsigned long bit11 : 1;
	unsigned long bit12 : 1;
	unsigned long bit13 : 1;
	unsigned long bit14 : 1;
	unsigned long bit15 : 1;
	unsigned long bit16 : 1;
	unsigned long bit17 : 1;
	unsigned long bit18 : 1;
	unsigned long bit19 : 1;
	unsigned long bit20 : 1;
	unsigned long bit21 : 1;
	unsigned long bit22 : 1;
	unsigned long bit23 : 1;
	unsigned long bit24 : 1;
	unsigned long bit25 : 1;
	unsigned long bit26 : 1;
	unsigned long bit27 : 1;
	unsigned long bit28 : 1;
	unsigned long bit29 : 1;
	unsigned long bit30 : 1;
	unsigned long bit31 : 1;
} _4byte_bit_field_;
#endif

#ifndef __AS__TYPE_AxStep_enum
#define __AS__TYPE_AxStep_enum
typedef enum AxStep_enum
{	enINITA = 0,
	enSTARTA = 1,
	enPOWER_ONA = 2,
	enAUTOMATIC = 3,
	enJOGPOSITIVE = 4,
	enJOGNEGATIVE = 5,
	enMANUAL = 6,
	enHOMEA = 7,
	enOPERATIONA = 8,
	enERRORA = 9,
} AxStep_enum;
#endif

#ifndef __AS__TYPE_AxisCmd_typ
#define __AS__TYPE_AxisCmd_typ
typedef struct AxisCmd_typ
{	plcbit Start;
	plcbit Stop;
	plcbit PrintMark;
	plcbit ErrorReset;
	plcbit AutoMode;
	plcbit JogFwd;
	plcbit JogBack;
	plcbit Home;
	plcbit SingleCutter;
} AxisCmd_typ;
#endif

#ifndef __AS__TYPE_AxisPara_typ
#define __AS__TYPE_AxisPara_typ
typedef struct AxisPara_typ
{	unsigned short Speed;
} AxisPara_typ;
#endif

#ifndef __AS__TYPE_AxisStatus_typ
#define __AS__TYPE_AxisStatus_typ
typedef struct AxisStatus_typ
{	plcbit JogNegReady;
	plcbit JogPosReady;
} AxisStatus_typ;
#endif

#ifndef __AS__TYPE_AxisCtrl_typ
#define __AS__TYPE_AxisCtrl_typ
typedef struct AxisCtrl_typ
{	AxisCmd_typ Cmd;
	AxisPara_typ Para;
	AxisStatus_typ Status;
} AxisCtrl_typ;
#endif

#ifndef __AS__TYPE_ACP10SWVER_typ
#define __AS__TYPE_ACP10SWVER_typ
typedef struct ACP10SWVER_typ
{	unsigned short nc_manager;
	unsigned short nc_system;
	unsigned char NOT_USE_1[4];
} ACP10SWVER_typ;
#endif

#ifndef __AS__TYPE_ACP10OBIHW_typ
#define __AS__TYPE_ACP10OBIHW_typ
typedef struct ACP10OBIHW_typ
{	unsigned char init;
	unsigned char reserve1;
	unsigned char acp_id;
	unsigned char acp_id_nr;
	unsigned char acp_typ;
	unsigned char ax_num;
	unsigned short reserve2;
	unsigned long product_code;
	unsigned long serial_nr;
} ACP10OBIHW_typ;
#endif

#ifndef __AS__TYPE_ACP10OBINF_typ
#define __AS__TYPE_ACP10OBINF_typ
typedef struct ACP10OBINF_typ
{	unsigned short net_if_typ;
	unsigned short net_if_idx;
	unsigned short node_nr;
	unsigned short nc_obj_typ;
	unsigned short nc_obj_idx;
	unsigned short reserve;
	unsigned char nc_obj_name[48];
	ACP10OBIHW_typ hardware;
} ACP10OBINF_typ;
#endif

#ifndef __AS__TYPE_ACP10SIMM1_typ
#define __AS__TYPE_ACP10SIMM1_typ
typedef struct ACP10SIMM1_typ
{	float inertia;
	float static_friction;
	float viscous_friction;
} ACP10SIMM1_typ;
#endif

#ifndef __AS__TYPE_ACP10SIMM2_typ
#define __AS__TYPE_ACP10SIMM2_typ
typedef struct ACP10SIMM2_typ
{	float inertia;
	float static_friction;
	float viscous_friction;
	float stiffness;
	float damping;
} ACP10SIMM2_typ;
#endif

#ifndef __AS__TYPE_ACP10SIMGB_typ
#define __AS__TYPE_ACP10SIMGB_typ
typedef struct ACP10SIMGB_typ
{	unsigned char direction;
	unsigned char reserve1;
	unsigned short reserve2;
	unsigned long in_rev;
	unsigned long out_rev;
} ACP10SIMGB_typ;
#endif

#ifndef __AS__TYPE_ACP10SIMPA_typ
#define __AS__TYPE_ACP10SIMPA_typ
typedef struct ACP10SIMPA_typ
{	unsigned short mode;
	unsigned short add_load_par_id;
	ACP10SIMM1_typ mass1;
	ACP10SIMM2_typ mass2;
	ACP10SIMGB_typ gear;
} ACP10SIMPA_typ;
#endif

#ifndef __AS__TYPE_ACP10SIM_typ
#define __AS__TYPE_ACP10SIM_typ
typedef struct ACP10SIM_typ
{	unsigned char init;
	unsigned char NOT_USE_1;
	unsigned char status;
	unsigned char acp_sim;
	unsigned char NOT_USE_2[4];
	ACP10SIMPA_typ parameter;
} ACP10SIM_typ;
#endif

#ifndef __AS__TYPE_ACP10GLIPA_typ
#define __AS__TYPE_ACP10GLIPA_typ
typedef struct ACP10GLIPA_typ
{	unsigned char ok;
	unsigned char error;
	unsigned short reserve;
	unsigned long datobj_ident;
	unsigned char data_modul[12];
} ACP10GLIPA_typ;
#endif

#ifndef __AS__TYPE_ACP10GLINI_typ
#define __AS__TYPE_ACP10GLINI_typ
typedef struct ACP10GLINI_typ
{	unsigned char init;
	unsigned char reserve1;
	unsigned short reserve2;
	ACP10GLIPA_typ init_par;
} ACP10GLINI_typ;
#endif

#ifndef __AS__TYPE_ACP10NSVRQ_typ
#define __AS__TYPE_ACP10NSVRQ_typ
typedef struct ACP10NSVRQ_typ
{	unsigned short par_id;
	unsigned short reserve;
} ACP10NSVRQ_typ;
#endif

#ifndef __AS__TYPE_ACP10NSVRS_typ
#define __AS__TYPE_ACP10NSVRS_typ
typedef struct ACP10NSVRS_typ
{	unsigned short par_id;
	unsigned short reserve;
} ACP10NSVRS_typ;
#endif

#ifndef __AS__TYPE_ACP10NETSV_typ
#define __AS__TYPE_ACP10NETSV_typ
typedef struct ACP10NETSV_typ
{	unsigned long data_adr;
	unsigned char data_text[32];
	ACP10NSVRQ_typ request;
	ACP10NSVRS_typ response;
} ACP10NETSV_typ;
#endif

#ifndef __AS__TYPE_ACP10NET_typ
#define __AS__TYPE_ACP10NET_typ
typedef struct ACP10NET_typ
{	unsigned char init;
	unsigned char phase;
	unsigned char init_allowed;
	unsigned char nc_sys_restart;
	unsigned short reserve;
	unsigned short reserve1;
	ACP10NETSV_typ service;
} ACP10NET_typ;
#endif

#ifndef __AS__TYPE_ACP10AXDBS_typ
#define __AS__TYPE_ACP10AXDBS_typ
typedef struct ACP10AXDBS_typ
{	unsigned char ok;
	unsigned char error;
	unsigned char reserve1;
	unsigned char reserve2;
	unsigned long data_len;
	unsigned long datobj_ident;
	unsigned long datobj_datadr;
} ACP10AXDBS_typ;
#endif

#ifndef __AS__TYPE_ACP10AXDBP_typ
#define __AS__TYPE_ACP10AXDBP_typ
typedef struct ACP10AXDBP_typ
{	unsigned char file_device[32];
	unsigned char datobj_name[32];
	unsigned short datobj_type;
	unsigned short datblock_par_id;
	unsigned short idx1_par_id;
	unsigned short idx1;
	unsigned short idx2_par_id;
	unsigned short idx2;
	unsigned char NOT_USE_1[8];
} ACP10AXDBP_typ;
#endif

#ifndef __AS__TYPE_ACP10AXDBL_typ
#define __AS__TYPE_ACP10AXDBL_typ
typedef struct ACP10AXDBL_typ
{	ACP10AXDBS_typ status;
	ACP10AXDBP_typ parameter;
} ACP10AXDBL_typ;
#endif

#ifndef __AS__TYPE_ACP10DISTA_typ
#define __AS__TYPE_ACP10DISTA_typ
typedef struct ACP10DISTA_typ
{	unsigned char reference;
	unsigned char pos_hw_end;
	unsigned char neg_hw_end;
	unsigned char trigger1;
	unsigned char trigger2;
	unsigned char enable;
	unsigned short reserve2;
} ACP10DISTA_typ;
#endif

#ifndef __AS__TYPE_ACP10DILEV_typ
#define __AS__TYPE_ACP10DILEV_typ
typedef struct ACP10DILEV_typ
{	unsigned short reference;
	unsigned short pos_hw_end;
	unsigned short neg_hw_end;
	unsigned short trigger1;
	unsigned short trigger2;
	unsigned short reserve;
} ACP10DILEV_typ;
#endif

#ifndef __AS__TYPE_ACP10DIFRC_typ
#define __AS__TYPE_ACP10DIFRC_typ
typedef struct ACP10DIFRC_typ
{	unsigned char reference;
	unsigned char pos_hw_end;
	unsigned char neg_hw_end;
	unsigned char trigger1;
	unsigned char trigger2;
	unsigned char reserve1;
	unsigned short reserve2;
} ACP10DIFRC_typ;
#endif

#ifndef __AS__TYPE_ACP10DIGIN_typ
#define __AS__TYPE_ACP10DIGIN_typ
typedef struct ACP10DIGIN_typ
{	unsigned char init;
	unsigned char reserve1;
	unsigned short reserve2;
	ACP10DISTA_typ status;
	ACP10DILEV_typ level;
	ACP10DIFRC_typ force;
} ACP10DIGIN_typ;
#endif

#ifndef __AS__TYPE_ACP10ENCSL_typ
#define __AS__TYPE_ACP10ENCSL_typ
typedef struct ACP10ENCSL_typ
{	unsigned long units;
	unsigned long rev_motor;
} ACP10ENCSL_typ;
#endif

#ifndef __AS__TYPE_ACP10ENCSC_typ
#define __AS__TYPE_ACP10ENCSC_typ
typedef struct ACP10ENCSC_typ
{	ACP10ENCSL_typ load;
} ACP10ENCSC_typ;
#endif

#ifndef __AS__TYPE_ACP10ENCPA_typ
#define __AS__TYPE_ACP10ENCPA_typ
typedef struct ACP10ENCPA_typ
{	unsigned char count_dir;
	unsigned char reserve1;
	unsigned short reserve2;
	ACP10ENCSC_typ scaling;
} ACP10ENCPA_typ;
#endif

#ifndef __AS__TYPE_ACP10ENCIF_typ
#define __AS__TYPE_ACP10ENCIF_typ
typedef struct ACP10ENCIF_typ
{	unsigned char init;
	unsigned char reserve1;
	unsigned short reserve2;
	ACP10ENCPA_typ parameter;
} ACP10ENCIF_typ;
#endif

#ifndef __AS__TYPE_ACP10AXLPA_typ
#define __AS__TYPE_ACP10AXLPA_typ
typedef struct ACP10AXLPA_typ
{	float v_pos;
	float v_neg;
	float a1_pos;
	float a2_pos;
	float a1_neg;
	float a2_neg;
	float t_jolt;
	float t_in_pos;
	signed long pos_sw_end;
	signed long neg_sw_end;
	unsigned char NOT_USE_1[4];
	float ds_warning;
	float ds_stop;
	float a_stop;
	float dv_stop;
	unsigned long dv_stop_mode;
} ACP10AXLPA_typ;
#endif

#ifndef __AS__TYPE_ACP10AXLIM_typ
#define __AS__TYPE_ACP10AXLIM_typ
typedef struct ACP10AXLIM_typ
{	unsigned char init;
	unsigned char reserve1;
	unsigned short reserve2;
	ACP10AXLPA_typ parameter;
} ACP10AXLIM_typ;
#endif

#ifndef __AS__TYPE_ACP10CTRPO_typ
#define __AS__TYPE_ACP10CTRPO_typ
typedef struct ACP10CTRPO_typ
{	float kv;
	float tn;
	float t_predict;
	float t_total;
	float p_max;
	float i_max;
} ACP10CTRPO_typ;
#endif

#ifndef __AS__TYPE_ACP10ISQFI_typ
#define __AS__TYPE_ACP10ISQFI_typ
typedef struct ACP10ISQFI_typ
{	unsigned short type;
	unsigned short reserve;
	float a0;
	float a1;
	float b0;
	float b1;
	float b2;
	unsigned short c0_par_id;
	unsigned short c1_par_id;
} ACP10ISQFI_typ;
#endif

#ifndef __AS__TYPE_ACP10CTRSP_typ
#define __AS__TYPE_ACP10CTRSP_typ
typedef struct ACP10CTRSP_typ
{	float kv;
	float tn;
	float t_filter;
	ACP10ISQFI_typ isq_filter1;
	ACP10ISQFI_typ isq_filter2;
	ACP10ISQFI_typ isq_filter3;
} ACP10CTRSP_typ;
#endif

#ifndef __AS__TYPE_ACP10CTRUF_typ
#define __AS__TYPE_ACP10CTRUF_typ
typedef struct ACP10CTRUF_typ
{	unsigned char type;
	unsigned char auto_config;
	unsigned short reserve;
	float u0;
	float un;
	float fn;
	float k_f_slip;
} ACP10CTRUF_typ;
#endif

#ifndef __AS__TYPE_ACP10CTRFF_typ
#define __AS__TYPE_ACP10CTRFF_typ
typedef struct ACP10CTRFF_typ
{	unsigned short mode;
	unsigned short reserve;
	float torque_load;
	float torque_pos;
	float torque_neg;
	float kv_torque;
	float inertia;
	float t_filter_a;
} ACP10CTRFF_typ;
#endif

#ifndef __AS__TYPE_ACP10CTRFB_typ
#define __AS__TYPE_ACP10CTRFB_typ
typedef struct ACP10CTRFB_typ
{	unsigned short mode;
	unsigned short reserve;
	float speed_mix_ratio;
	float speed_kv;
} ACP10CTRFB_typ;
#endif

#ifndef __AS__TYPE_ACP10CTRMODM1_typ
#define __AS__TYPE_ACP10CTRMODM1_typ
typedef struct ACP10CTRMODM1_typ
{	float inertia;
	float viscous_friction;
} ACP10CTRMODM1_typ;
#endif

#ifndef __AS__TYPE_ACP10CTRMODM2_typ
#define __AS__TYPE_ACP10CTRMODM2_typ
typedef struct ACP10CTRMODM2_typ
{	float inertia;
	float viscous_friction;
	float stiffness;
	float damping;
} ACP10CTRMODM2_typ;
#endif

#ifndef __AS__TYPE_ACP10CTRMODEL_typ
#define __AS__TYPE_ACP10CTRMODEL_typ
typedef struct ACP10CTRMODEL_typ
{	ACP10CTRMODM1_typ mass1;
	ACP10CTRMODM2_typ mass2;
} ACP10CTRMODEL_typ;
#endif

#ifndef __AS__TYPE_ACP10CTRL_typ
#define __AS__TYPE_ACP10CTRL_typ
typedef struct ACP10CTRL_typ
{	unsigned char init;
	unsigned char ready;
	unsigned char status;
	unsigned char mode;
	ACP10CTRPO_typ position;
	ACP10CTRSP_typ speed;
	ACP10CTRUF_typ uf;
	ACP10CTRFF_typ ff;
	ACP10CTRFB_typ fb;
	ACP10CTRMODEL_typ model;
} ACP10CTRL_typ;
#endif

#ifndef __AS__TYPE_ACP10AXSTI_typ
#define __AS__TYPE_ACP10AXSTI_typ
typedef struct ACP10AXSTI_typ
{	unsigned char command;
	unsigned char reserve1;
	unsigned short reserve2;
} ACP10AXSTI_typ;
#endif

#ifndef __AS__TYPE_ACP10AXSTP_typ
#define __AS__TYPE_ACP10AXSTP_typ
typedef struct ACP10AXSTP_typ
{	unsigned char decel_ramp;
	unsigned char controller;
	unsigned short reserve;
} ACP10AXSTP_typ;
#endif

#ifndef __AS__TYPE_ACP10AXSTQ_typ
#define __AS__TYPE_ACP10AXSTQ_typ
typedef struct ACP10AXSTQ_typ
{	unsigned char decel_ramp;
	unsigned char reserve1;
	unsigned short reserve2;
	float t_jolt;
} ACP10AXSTQ_typ;
#endif

#ifndef __AS__TYPE_ACP10AXSTD_typ
#define __AS__TYPE_ACP10AXSTD_typ
typedef struct ACP10AXSTD_typ
{	unsigned char decel_ramp;
	unsigned char reserve1;
	unsigned short reserve2;
} ACP10AXSTD_typ;
#endif

#ifndef __AS__TYPE_ACP10AXSTO_typ
#define __AS__TYPE_ACP10AXSTO_typ
typedef struct ACP10AXSTO_typ
{	unsigned char init;
	unsigned char NOT_USE_1;
	unsigned short reserve2;
	ACP10AXSTI_typ index;
	struct ACP10AXSTP_typ parameter[4];
	ACP10AXSTQ_typ quickstop;
	ACP10AXSTD_typ drive_error;
} ACP10AXSTO_typ;
#endif

#ifndef __AS__TYPE_ACP10HOMST_typ
#define __AS__TYPE_ACP10HOMST_typ
typedef struct ACP10HOMST_typ
{	unsigned char ok;
	unsigned char reserve1;
	unsigned short reserve2;
	float tr_s_rel;
	signed long offset;
} ACP10HOMST_typ;
#endif

#ifndef __AS__TYPE_ACP10HOMPA_typ
#define __AS__TYPE_ACP10HOMPA_typ
typedef struct ACP10HOMPA_typ
{	signed long s;
	float v_switch;
	float v_trigger;
	float a;
	unsigned char mode;
	unsigned char edge_sw;
	unsigned char start_dir;
	unsigned char trigg_dir;
	unsigned char ref_pulse;
	unsigned char fix_dir;
	unsigned char reserve1;
	unsigned char reserve2;
	float tr_s_block;
	float torque_lim;
	float ds_block;
	float ds_stop;
} ACP10HOMPA_typ;
#endif

#ifndef __AS__TYPE_ACP10HOME_typ
#define __AS__TYPE_ACP10HOME_typ
typedef struct ACP10HOME_typ
{	unsigned char init;
	unsigned char reserve1;
	unsigned short reserve2;
	ACP10HOMST_typ status;
	ACP10HOMPA_typ parameter;
} ACP10HOME_typ;
#endif

#ifndef __AS__TYPE_ACP10BMVST_typ
#define __AS__TYPE_ACP10BMVST_typ
typedef struct ACP10BMVST_typ
{	unsigned char in_pos;
	unsigned char reserve1;
	unsigned short reserve2;
} ACP10BMVST_typ;
#endif

#ifndef __AS__TYPE_ACP10BMVOV_typ
#define __AS__TYPE_ACP10BMVOV_typ
typedef struct ACP10BMVOV_typ
{	unsigned short v;
	unsigned short a;
} ACP10BMVOV_typ;
#endif

#ifndef __AS__TYPE_ACP10BMVPA_typ
#define __AS__TYPE_ACP10BMVPA_typ
typedef struct ACP10BMVPA_typ
{	signed long s;
	float v_pos;
	float v_neg;
	float a1_pos;
	float a2_pos;
	float a1_neg;
	float a2_neg;
} ACP10BMVPA_typ;
#endif

#ifndef __AS__TYPE_ACP10TRSTP_typ
#define __AS__TYPE_ACP10TRSTP_typ
typedef struct ACP10TRSTP_typ
{	unsigned char init;
	unsigned char event;
	unsigned short reserve;
	signed long s_rest;
	unsigned char NOT_USE_1[12];
} ACP10TRSTP_typ;
#endif

#ifndef __AS__TYPE_ACP10BAMOV_typ
#define __AS__TYPE_ACP10BAMOV_typ
typedef struct ACP10BAMOV_typ
{	unsigned char init;
	unsigned char reserve1;
	unsigned short reserve2;
	ACP10BMVST_typ status;
	ACP10BMVOV_typ override;
	ACP10BMVPA_typ parameter;
	ACP10TRSTP_typ trg_stop;
} ACP10BAMOV_typ;
#endif

#ifndef __AS__TYPE_ACP10AXMOV_typ
#define __AS__TYPE_ACP10AXMOV_typ
typedef struct ACP10AXMOV_typ
{	unsigned short mode;
	unsigned short detail;
	ACP10AXSTO_typ stop;
	ACP10HOME_typ homing;
	ACP10BAMOV_typ basis;
} ACP10AXMOV_typ;
#endif

#ifndef __AS__TYPE_ACP10SUOST_typ
#define __AS__TYPE_ACP10SUOST_typ
typedef struct ACP10SUOST_typ
{	unsigned long ident;
	unsigned char ok;
	unsigned char error;
	unsigned char reserve1;
	unsigned char reserve2;
} ACP10SUOST_typ;
#endif

#ifndef __AS__TYPE_ACP10SUOPA_typ
#define __AS__TYPE_ACP10SUOPA_typ
typedef struct ACP10SUOPA_typ
{	unsigned char name[12];
} ACP10SUOPA_typ;
#endif

#ifndef __AS__TYPE_ACP10SUOBJ_typ
#define __AS__TYPE_ACP10SUOBJ_typ
typedef struct ACP10SUOBJ_typ
{	ACP10SUOST_typ status;
	ACP10SUOPA_typ parameter;
} ACP10SUOBJ_typ;
#endif

#ifndef __AS__TYPE_ACP10SUMAS_typ
#define __AS__TYPE_ACP10SUMAS_typ
typedef struct ACP10SUMAS_typ
{	unsigned short mode;
	unsigned char ok;
	unsigned char error;
	float quality;
} ACP10SUMAS_typ;
#endif

#ifndef __AS__TYPE_ACP10SUMAO_typ
#define __AS__TYPE_ACP10SUMAO_typ
typedef struct ACP10SUMAO_typ
{	unsigned char z_p;
	unsigned char phase;
	unsigned short reserve2;
	float u_const;
	float v_max;
	float trq_0;
	float trq_n;
	float trq_max;
	float trq_const;
	float i_0;
	float i_max;
	float i_m;
	float phase_cross_sect;
	float invcl_a1;
	float invcl_a2;
} ACP10SUMAO_typ;
#endif

#ifndef __AS__TYPE_ACP10SUMAP_typ
#define __AS__TYPE_ACP10SUMAP_typ
typedef struct ACP10SUMAP_typ
{	unsigned short mode;
	unsigned short reserve;
	float u_n;
	float i_n;
	float v_n;
	float f_n;
	float cos_phi;
	float t_tripping_therm;
	ACP10SUMAO_typ optional;
} ACP10SUMAP_typ;
#endif

#ifndef __AS__TYPE_ACP10SUMA_typ
#define __AS__TYPE_ACP10SUMA_typ
typedef struct ACP10SUMA_typ
{	ACP10SUMAS_typ status;
	ACP10SUMAP_typ parameter;
} ACP10SUMA_typ;
#endif

#ifndef __AS__TYPE_ACP10SUMSS_typ
#define __AS__TYPE_ACP10SUMSS_typ
typedef struct ACP10SUMSS_typ
{	unsigned short mode;
	unsigned char ok;
	unsigned char error;
	float quality;
} ACP10SUMSS_typ;
#endif

#ifndef __AS__TYPE_ACP10SUMSO_typ
#define __AS__TYPE_ACP10SUMSO_typ
typedef struct ACP10SUMSO_typ
{	unsigned char phase;
	unsigned char reserve1;
	unsigned short reserve2;
	float u_const;
	float v_max;
	float trq_0;
	float trq_const;
	float i_0;
	float phase_cross_sect;
	float invcl_a1;
	float invcl_a2;
} ACP10SUMSO_typ;
#endif

#ifndef __AS__TYPE_ACP10SUMSP_typ
#define __AS__TYPE_ACP10SUMSP_typ
typedef struct ACP10SUMSP_typ
{	unsigned short mode;
	unsigned char z_p;
	unsigned char reserve;
	float u_n;
	float i_n;
	float v_n;
	float trq_n;
	float trq_max;
	float i_max;
	float t_tripping_therm;
	ACP10SUMSO_typ optional;
} ACP10SUMSP_typ;
#endif

#ifndef __AS__TYPE_ACP10SUMS_typ
#define __AS__TYPE_ACP10SUMS_typ
typedef struct ACP10SUMS_typ
{	ACP10SUMSS_typ status;
	ACP10SUMSP_typ parameter;
} ACP10SUMS_typ;
#endif

#ifndef __AS__TYPE_ACP10SUPHS_typ
#define __AS__TYPE_ACP10SUPHS_typ
typedef struct ACP10SUPHS_typ
{	unsigned short mode;
	unsigned char ok;
	unsigned char error;
	float rho_0;
	unsigned char z_p;
	unsigned char reserve1;
	unsigned short reserve2;
} ACP10SUPHS_typ;
#endif

#ifndef __AS__TYPE_ACP10SUPHP_typ
#define __AS__TYPE_ACP10SUPHP_typ
typedef struct ACP10SUPHP_typ
{	unsigned short mode;
	unsigned short reserve;
	float i;
	float t;
} ACP10SUPHP_typ;
#endif

#ifndef __AS__TYPE_ACP10SUPH_typ
#define __AS__TYPE_ACP10SUPH_typ
typedef struct ACP10SUPH_typ
{	ACP10SUPHS_typ status;
	ACP10SUPHP_typ parameter;
} ACP10SUPH_typ;
#endif

#ifndef __AS__TYPE_ACP10SUCST_typ
#define __AS__TYPE_ACP10SUCST_typ
typedef struct ACP10SUCST_typ
{	unsigned short mode;
	unsigned char ok;
	unsigned char error;
} ACP10SUCST_typ;
#endif

#ifndef __AS__TYPE_ACP10SUCPA_typ
#define __AS__TYPE_ACP10SUCPA_typ
typedef struct ACP10SUCPA_typ
{	unsigned short mode;
	unsigned char orientation;
	unsigned char operating_point;
	float i_max_percent;
	float v_max_percent;
	signed long s_max;
	float ds_max;
	float kv_percent;
	unsigned long signal_order;
	float kv_max;
	float a;
	unsigned short signal_type;
	unsigned short reserve;
	float signal_f_start;
	float signal_f_stop;
	float signal_time;
} ACP10SUCPA_typ;
#endif

#ifndef __AS__TYPE_ACP10SUCTR_typ
#define __AS__TYPE_ACP10SUCTR_typ
typedef struct ACP10SUCTR_typ
{	ACP10SUCST_typ status;
	ACP10SUCPA_typ parameter;
} ACP10SUCTR_typ;
#endif

#ifndef __AS__TYPE_ACP10SUIRS_typ
#define __AS__TYPE_ACP10SUIRS_typ
typedef struct ACP10SUIRS_typ
{	unsigned short mode;
	unsigned char ok;
	unsigned char error;
	float quality;
} ACP10SUIRS_typ;
#endif

#ifndef __AS__TYPE_ACP10SUIRP_typ
#define __AS__TYPE_ACP10SUIRP_typ
typedef struct ACP10SUIRP_typ
{	unsigned short mode;
	unsigned char reserve;
	unsigned char ref_system;
	float pos_offset;
	float v;
} ACP10SUIRP_typ;
#endif

#ifndef __AS__TYPE_ACP10SUIR_typ
#define __AS__TYPE_ACP10SUIR_typ
typedef struct ACP10SUIR_typ
{	ACP10SUIRS_typ status;
	ACP10SUIRP_typ parameter;
} ACP10SUIR_typ;
#endif

#ifndef __AS__TYPE_ACP10SUMOVST_typ
#define __AS__TYPE_ACP10SUMOVST_typ
typedef struct ACP10SUMOVST_typ
{	unsigned short mode;
	unsigned char ok;
	unsigned char error;
} ACP10SUMOVST_typ;
#endif

#ifndef __AS__TYPE_ACP10SUMOPA_typ
#define __AS__TYPE_ACP10SUMOPA_typ
typedef struct ACP10SUMOPA_typ
{	unsigned short mode;
	unsigned char start_dir;
	unsigned char fix_dir;
	signed long s_max;
} ACP10SUMOPA_typ;
#endif

#ifndef __AS__TYPE_ACP10SUMOV_typ
#define __AS__TYPE_ACP10SUMOV_typ
typedef struct ACP10SUMOV_typ
{	ACP10SUMOVST_typ status;
	ACP10SUMOPA_typ parameter;
} ACP10SUMOV_typ;
#endif

#ifndef __AS__TYPE_ACP10SETUP_typ
#define __AS__TYPE_ACP10SETUP_typ
typedef struct ACP10SETUP_typ
{	unsigned char status;
	unsigned char active;
	unsigned short detail;
	ACP10SUOBJ_typ datobj;
	ACP10SUMA_typ motor_induction;
	ACP10SUMS_typ motor_synchron;
	ACP10SUPH_typ motor_phasing;
	ACP10SUCTR_typ controller;
	ACP10SUIR_typ isq_ripple;
	ACP10SUMOV_typ move;
} ACP10SETUP_typ;
#endif

#ifndef __AS__TYPE_ACP10AXMOS_typ
#define __AS__TYPE_ACP10AXMOS_typ
typedef struct ACP10AXMOS_typ
{	unsigned char error;
	unsigned char warning;
	unsigned char ds_warning;
	unsigned char reserve;
} ACP10AXMOS_typ;
#endif

#ifndef __AS__TYPE_ACP10AXMON_typ
#define __AS__TYPE_ACP10AXMON_typ
typedef struct ACP10AXMON_typ
{	signed long s;
	float v;
	ACP10AXMOS_typ status;
} ACP10AXMON_typ;
#endif

#ifndef __AS__TYPE_ACP10MSCNT_typ
#define __AS__TYPE_ACP10MSCNT_typ
typedef struct ACP10MSCNT_typ
{	unsigned char error;
	unsigned char warning;
	unsigned char mc_fb_error;
	unsigned char reserve;
} ACP10MSCNT_typ;
#endif

#ifndef __AS__TYPE_ACP10MSREC_typ
#define __AS__TYPE_ACP10MSREC_typ
typedef struct ACP10MSREC_typ
{	unsigned short par_id;
	unsigned short number;
	unsigned long info;
} ACP10MSREC_typ;
#endif

#ifndef __AS__TYPE_ACP10MTXST_typ
#define __AS__TYPE_ACP10MTXST_typ
typedef struct ACP10MTXST_typ
{	unsigned short lines;
	unsigned short error;
} ACP10MTXST_typ;
#endif

#ifndef __AS__TYPE_ACP10MTXPA_typ
#define __AS__TYPE_ACP10MTXPA_typ
typedef struct ACP10MTXPA_typ
{	unsigned short format;
	unsigned short columns;
	unsigned char data_modul[12];
	unsigned short data_len;
	unsigned short reserve;
	unsigned long data_adr;
	unsigned long record_adr;
} ACP10MTXPA_typ;
#endif

#ifndef __AS__TYPE_ACP10MSTXT_typ
#define __AS__TYPE_ACP10MSTXT_typ
typedef struct ACP10MSTXT_typ
{	ACP10MTXST_typ status;
	ACP10MTXPA_typ parameter;
} ACP10MSTXT_typ;
#endif

#ifndef __AS__TYPE_ACP10MSCMDERR_typ
#define __AS__TYPE_ACP10MSCMDERR_typ
typedef struct ACP10MSCMDERR_typ
{	unsigned short type;
	unsigned char ok;
	unsigned char error;
} ACP10MSCMDERR_typ;
#endif

#ifndef __AS__TYPE_ACP10MSG_typ
#define __AS__TYPE_ACP10MSG_typ
typedef struct ACP10MSG_typ
{	ACP10MSCNT_typ count;
	ACP10MSREC_typ record;
	ACP10MSTXT_typ text;
	ACP10MSCMDERR_typ cmd_error;
} ACP10MSG_typ;
#endif

#ifndef __AS__TYPE_ACP10NCTST_typ
#define __AS__TYPE_ACP10NCTST_typ
typedef struct ACP10NCTST_typ
{	unsigned char Open_UseApplNcObj;
	unsigned char Close_NoMoveAbort;
	unsigned char reserve1;
	unsigned char reserve2;
} ACP10NCTST_typ;
#endif

#ifndef __AS__TYPE_ACP10AXIS_typ
#define __AS__TYPE_ACP10AXIS_typ
typedef struct ACP10AXIS_typ
{	unsigned char NOT_USE_1[4];
	unsigned short size;
	unsigned char NOT_USE_2[2];
	ACP10SWVER_typ sw_version;
	ACP10OBINF_typ nc_obj_inf;
	ACP10SIM_typ simulation;
	ACP10GLINI_typ global;
	ACP10NET_typ network;
	ACP10AXDBL_typ datblock;
	ACP10DIGIN_typ dig_in;
	ACP10ENCIF_typ encoder_if;
	ACP10AXLIM_typ limit;
	ACP10CTRL_typ controller;
	ACP10AXMOV_typ move;
	ACP10SETUP_typ setup;
	ACP10AXMON_typ monitor;
	ACP10MSG_typ message;
	ACP10NCTST_typ nc_test;
	unsigned char NOT_USE_3[60];
} ACP10AXIS_typ;
#endif

#ifndef __AS__TYPE_MpAxisMoveDirectionEnum
#define __AS__TYPE_MpAxisMoveDirectionEnum
typedef enum MpAxisMoveDirectionEnum
{	mpAXIS_DIR_POSITIVE = 0,
	mpAXIS_DIR_NEGATIVE = 1,
	mpAXIS_DIR_CURRENT = 2,
	mpAXIS_DIR_SHORTEST_WAY = 3,
	mpAXIS_DIR_EXCEED_PERIOD = 8,
} MpAxisMoveDirectionEnum;
#endif

#ifndef __AS__TYPE_MpAxisHomeModeEnum
#define __AS__TYPE_MpAxisHomeModeEnum
typedef enum MpAxisHomeModeEnum
{	mpAXIS_HOME_MODE_DEFAULT = 0,
	mpAXIS_HOME_MODE_ABS_SWITCH = 2,
	mpAXIS_HOME_MODE_SWITCH_GATE = 8,
	mpAXIS_HOME_MODE_LIMIT_SWITCH = 3,
	mpAXIS_HOME_MODE_REF_PULSE = 5,
	mpAXIS_HOME_MODE_DIRECT = 1,
	mpAXIS_HOME_MODE_ABSOLUTE = 4,
	mpAXIS_HOME_MODE_ABSOLUTE_CORR = 6,
	mpAXIS_HOME_MODE_DCM = 9,
	mpAXIS_HOME_MODE_DCM_CORR = 10,
	mpAXIS_HOME_MODE_RESTORE_POS = 11,
	mpAXIS_HOME_MODE_AXIS_REF = 12,
	mpAXIS_HOME_MODE_BLOCK_TORQUE = 13,
	mpAXIS_HOME_MODE_BLOCK_DS = 14,
} MpAxisHomeModeEnum;
#endif

#ifndef __AS__TYPE_MpAxisHomeMoveDirectionEnum
#define __AS__TYPE_MpAxisHomeMoveDirectionEnum
typedef enum MpAxisHomeMoveDirectionEnum
{	mpAXIS_HOME_DIR_POSITIVE = 0,
	mpAXIS_HOME_DIR_NEGATIVE = 1,
} MpAxisHomeMoveDirectionEnum;
#endif

#ifndef __AS__TYPE_MpAxisHomeOptionEnum
#define __AS__TYPE_MpAxisHomeOptionEnum
typedef enum MpAxisHomeOptionEnum
{	mpAXIS_HOME_OPTION_OFF = 0,
	mpAXIS_HOME_OPTION_ON = 1,
} MpAxisHomeOptionEnum;
#endif

#ifndef __AS__TYPE_MpAxisHomingType
#define __AS__TYPE_MpAxisHomingType
typedef struct MpAxisHomingType
{	MpAxisHomeModeEnum Mode;
	double Position;
	float StartVelocity;
	float HomingVelocity;
	double SensorOffset;
	float Acceleration;
	MpAxisHomeMoveDirectionEnum StartDirection;
	MpAxisHomeMoveDirectionEnum HomingDirection;
	MpAxisHomeOptionEnum NoDirectionChange;
	MpAxisHomeMoveDirectionEnum SwitchEdge;
	MpAxisHomeOptionEnum ReferencePulse;
	double ReferencePulseBlockingDistance;
	float TorqueLimit;
	double BlockDetectionPositionError;
	double PositionErrorStopLimit;
	unsigned long EndlessPositionDataRef;
} MpAxisHomingType;
#endif

#ifndef __AS__TYPE_MpAxisJogType
#define __AS__TYPE_MpAxisJogType
typedef struct MpAxisJogType
{	float Acceleration;
	float Deceleration;
	float Velocity;
	double LowerLimit;
	double UpperLimit;
} MpAxisJogType;
#endif

#ifndef __AS__TYPE_MpAxisStopType
#define __AS__TYPE_MpAxisStopType
typedef struct MpAxisStopType
{	float Deceleration;
	plcbit StopInPhase;
	double Phase;
} MpAxisStopType;
#endif

#ifndef __AS__TYPE_MpAxisTriggerSourceEnum
#define __AS__TYPE_MpAxisTriggerSourceEnum
typedef enum MpAxisTriggerSourceEnum
{	mpAXIS_TRIGGER1 = 20,
	mpAXIS_TRIGGER2 = 22,
} MpAxisTriggerSourceEnum;
#endif

#ifndef __AS__TYPE_MpAxisTriggerEdgeEnum
#define __AS__TYPE_MpAxisTriggerEdgeEnum
typedef enum MpAxisTriggerEdgeEnum
{	mpAXIS_TRIGGER_EDGE_POS = 0,
	mpAXIS_TRIGGER_EDGE_NEG = 1,
} MpAxisTriggerEdgeEnum;
#endif

#ifndef __AS__TYPE_MpAxisStopAfterTriggerType
#define __AS__TYPE_MpAxisStopAfterTriggerType
typedef struct MpAxisStopAfterTriggerType
{	plcbit Enable;
	double TriggerDistance;
	plcbit ForceTriggerDistance;
	MpAxisTriggerSourceEnum Source;
	MpAxisTriggerEdgeEnum Edge;
} MpAxisStopAfterTriggerType;
#endif

#ifndef __AS__TYPE_MpAxisTorqueLimitType
#define __AS__TYPE_MpAxisTorqueLimitType
typedef struct MpAxisTorqueLimitType
{	float Limit;
	float Window;
} MpAxisTorqueLimitType;
#endif

#ifndef __AS__TYPE_MpAxisReadInfoModeEnum
#define __AS__TYPE_MpAxisReadInfoModeEnum
typedef enum MpAxisReadInfoModeEnum
{	mpAXIS_READ_OFF = 0,
	mpAXIS_READ_CYCLIC = 1,
	mpAXIS_READ_MULTIPLEXED = 2,
	mpAXIS_READ_POLLING_1s = 3,
	mpAXIS_READ_POLLING_5s = 4,
} MpAxisReadInfoModeEnum;
#endif

#ifndef __AS__TYPE_MpAxisCyclicReadSetupType
#define __AS__TYPE_MpAxisCyclicReadSetupType
typedef struct MpAxisCyclicReadSetupType
{	MpAxisReadInfoModeEnum TorqueMode;
	MpAxisReadInfoModeEnum LagErrorMode;
	MpAxisReadInfoModeEnum MotorTempMode;
	MpAxisReadInfoModeEnum UserChannelMode;
} MpAxisCyclicReadSetupType;
#endif

#ifndef __AS__TYPE_MpAxisAutotuneModeEnum
#define __AS__TYPE_MpAxisAutotuneModeEnum
typedef enum MpAxisAutotuneModeEnum
{	mpAXIS_TUNE_AUTOMATIC = 0,
	mpAXIS_TUNE_SPEED = 2,
	mpAXIS_TUNE_POSITION = 1,
	mpAXIS_TUNE_TEST = 31,
	mpAXIS_TUNE_SPEED_ISQ_F1 = 130,
	mpAXIS_TUNE_SPEED_T_FLTR = 66,
	mpAXIS_TUNE_SPEED_T_FLTR_ISQ_F1 = 194,
	mpAXIS_TUNE_SPEED_FLTR = 6,
	mpAXIS_TUNE_ISQ_F1 = 128,
	mpAXIS_TUNE_ISQ_F1_F2 = 384,
	mpAXIS_TUNE_ISQ_F1_F2_F3 = 896,
	mpAXIS_TUNE_FF = 32,
	mpAXIS_TUNE_FF_ONLY_POS = 33,
	mpAXIS_TUNE_FF_ONLY_NEG = 34,
} MpAxisAutotuneModeEnum;
#endif

#ifndef __AS__TYPE_MpAxisFeedForwardModeEnum
#define __AS__TYPE_MpAxisFeedForwardModeEnum
typedef enum MpAxisFeedForwardModeEnum
{	mpAXIS_FF_DISABLED = 0,
	mpAXIS_FF_BOTH = 1,
	mpAXIS_FF_ONLY_POS = 2,
	mpAXIS_FF_ONLY_NEG = 3,
} MpAxisFeedForwardModeEnum;
#endif

#ifndef __AS__TYPE_MpAxisAutotuneType
#define __AS__TYPE_MpAxisAutotuneType
typedef struct MpAxisAutotuneType
{	MpAxisAutotuneModeEnum Mode;
	MpAxisFeedForwardModeEnum FeedForward;
	plcbit Vertical;
	float MaxCurrentPercent;
	float MaxSpeedPercent;
	double MaxDistance;
	float ProportionalAmplification;
} MpAxisAutotuneType;
#endif

#ifndef __AS__TYPE_MpAxisBasicParType
#define __AS__TYPE_MpAxisBasicParType
typedef struct MpAxisBasicParType
{	float Acceleration;
	float Deceleration;
	float Velocity;
	double Position;
	double Distance;
	MpAxisMoveDirectionEnum Direction;
	MpAxisHomingType Home;
	MpAxisJogType Jog;
	MpAxisStopType Stop;
	MpAxisStopAfterTriggerType StopAfterTrigger;
	MpAxisTorqueLimitType Torque;
	MpAxisCyclicReadSetupType CyclicRead;
	MpAxisAutotuneType Autotune;
} MpAxisBasicParType;
#endif

#ifndef __AS__TYPE_MpAxisCyclicReadValueType
#define __AS__TYPE_MpAxisCyclicReadValueType
typedef struct MpAxisCyclicReadValueType
{	plcbit Valid;
	double Value;
} MpAxisCyclicReadValueType;
#endif

#ifndef __AS__TYPE_MpAxisCyclicReadType
#define __AS__TYPE_MpAxisCyclicReadType
typedef struct MpAxisCyclicReadType
{	MpAxisCyclicReadValueType Torque;
	MpAxisCyclicReadValueType LagError;
	MpAxisCyclicReadValueType MotorTemperature;
	MpAxisCyclicReadValueType UserChannelParameterID;
} MpAxisCyclicReadType;
#endif

#ifndef __AS__TYPE_MpAxisBootPhaseEnum
#define __AS__TYPE_MpAxisBootPhaseEnum
typedef enum MpAxisBootPhaseEnum
{	mpAXIS_BLP_NETWORK_INACTIVE = 0,
	mpAXIS_BLP_NETWORK_INIT_STARTED = 1,
	mpAXIS_BLP_WAIT_INIT_HIGH_PRIO = 5,
	mpAXIS_BLP_HW_WAIT = 9,
	mpAXIS_BLP_HW_LINKED = 10,
	mpAXIS_BLP_HW_START = 20,
	mpAXIS_BLP_HW_UPDATE = 30,
	mpAXIS_BLP_HW_UPDATE_OTHER_DRV = 31,
	mpAXIS_BLP_FW_UPDATE = 40,
	mpAXIS_BLP_FW_UPDATE_OTHER_DRV = 41,
	mpAXIS_BLP_FW_START = 50,
	mpAXIS_BLP_WAIT_INIT_LOW_PRIO = 55,
	mpAXIS_BLP_DOWNLOAD_DEF_PARAMS = 60,
	mpAXIS_BLP_DOWNLOAD_INI_PARAMS = 70,
	mpAXIS_BLP_HW_INFO_FROM_DRIVE = 80,
	mpAXIS_BLP_DONE = 90,
} MpAxisBootPhaseEnum;
#endif

#ifndef __AS__TYPE_MpAxisPlcOpenStateEnum
#define __AS__TYPE_MpAxisPlcOpenStateEnum
typedef enum MpAxisPlcOpenStateEnum
{	mpAXIS_DISABLED = 0,
	mpAXIS_STANDSTILL = 1,
	mpAXIS_ERRORSTOP = 10,
	mpAXIS_STOPPING = 9,
	mpAXIS_DISCRETE_MOTION = 2,
	mpAXIS_CONTINUOUS_MOTION = 3,
	mpAXIS_SYNCHRONIZED_MOTION = 4,
	mpAXIS_HOMING = 5,
} MpAxisPlcOpenStateEnum;
#endif

#ifndef __AS__TYPE_MpAxisDigitalIOStatusType
#define __AS__TYPE_MpAxisDigitalIOStatusType
typedef struct MpAxisDigitalIOStatusType
{	plcbit DriveEnable;
	plcbit HomeSwitch;
	plcbit PositiveLimitSwitch;
	plcbit NegativeLimitSwitch;
	plcbit Trigger1;
	plcbit Trigger2;
} MpAxisDigitalIOStatusType;
#endif

#ifndef __AS__TYPE_MpAxisNetworkTypeEnum
#define __AS__TYPE_MpAxisNetworkTypeEnum
typedef enum MpAxisNetworkTypeEnum
{	mpAXIS_CAN_NETWORK = 0,
	mpAXIS_PLK_NETWORK = 1,
	mpAXIS_SDC_NETWORK = 129,
} MpAxisNetworkTypeEnum;
#endif

#ifndef __AS__TYPE_MpAxisDeviceTypeEnum
#define __AS__TYPE_MpAxisDeviceTypeEnum
typedef enum MpAxisDeviceTypeEnum
{	mpAXIS_DEVICE_UNKNOWN = 0,
	mpAXIS_ACOPOS = 1,
	mpAXIS_VIRTUAL = 3,
	mpAXIS_ACOPOSmulti65m = 4,
	mpAXIS_ACOPOSmulti = 5,
	mpAXIS_ACOPOSmulti_PPS = 6,
	mpAXIS_ACOPOSmulti_PS = 2,
	mpAXIS_ACOPOSmicro = 7,
	mpAXIS_ACOPOSmulti65 = 8,
	mpAXIS_ACOPOS_P3 = 12,
	mpAXIS_ACOPOS_SDC = 128,
	mpAXIS_ACOPOS_SIM = 129,
} MpAxisDeviceTypeEnum;
#endif

#ifndef __AS__TYPE_MpAxisAddInfoHardwareType
#define __AS__TYPE_MpAxisAddInfoHardwareType
typedef struct MpAxisAddInfoHardwareType
{	unsigned short NodeID;
	unsigned char Channel;
	MpAxisNetworkTypeEnum NetworkType;
	MpAxisDeviceTypeEnum DeviceType;
} MpAxisAddInfoHardwareType;
#endif

#ifndef __AS__TYPE_MpAxisErrorEnum
#define __AS__TYPE_MpAxisErrorEnum
typedef enum MpAxisErrorEnum
{	mpAXIS_NO_ERROR = 0,
	mpAXIS_ERR_ACTIVATION = -1064239103,
	mpAXIS_ERR_MPLINK_NULL = -1064239102,
	mpAXIS_ERR_MPLINK_INVALID = -1064239101,
	mpAXIS_ERR_MPLINK_CHANGED = -1064239100,
	mpAXIS_ERR_MPLINK_CORRUPT = -1064239099,
	mpAXIS_ERR_MPLINK_IN_USE = -1064239098,
	mpAXIS_ERR_PAR_NULL = -1064239097,
	mpAXIS_ERR_CONFIG_NULL = -1064239096,
	mpAXIS_ERR_CONFIG_NO_PV = -1064239095,
	mpAXIS_ERR_CONFIG_LOAD = -1064239094,
	mpAXIS_WRN_CONFIG_LOAD = -2137980917,
	mpAXIS_ERR_CONFIG_SAVE = -1064239092,
	mpAXIS_ERR_CONFIG_INVALID = -1064239091,
	mpAXIS_ERR_AXIS_HANDLE_NULL = -1064074752,
	mpAXIS_WRN_ERROR_TABLE_MISSING = -2137816575,
	mpAXIS_WRN_CFG_WAIT_ERROR_RESET = -2137816574,
	mpAXIS_WRN_CFG_WAIT_POWER_OFF = -2137816573,
	mpAXIS_WRN_CFG_WAIT_STANDSTILL = -2137816572,
	mpAXIS_ERR_PLC_OPEN = -1064074747,
	mpAXIS_WRN_PLC_OPEN = -2137816570,
	mpAXIS_WRN_READ_TORQUE_OFF = -2137816569,
	mpAXIS_ERR_MAX_TORQUE_REACHED = -1064074744,
	mpAXIS_ERR_SLAVE_NOT_FOUND = -1064074732,
	mpAXIS_ERR_MASTER_NOT_FOUND = -1064074731,
	mpAXIS_ERR_WRONG_DENOMINATOR = -1064074730,
	mpAXIS_ERR_WRONG_NUMERATOR = -1064074729,
	mpAXIS_ERR_NO_CAM_NAME = -1064074728,
	mpAXIS_WRN_SLAVE_NOT_READY = -2137816551,
	mpAXIS_ERR_CHECK_SLAVE_STATUS = -1064074726,
	mpAXIS_ERR_CMD_WRONG_AXISTYPE = -1064074725,
	mpAXIS_WRN_PARAMETER_LIMITED = -2137816548,
	mpAXIS_WRN_MULTIPLE_COMMAND = -2137816547,
	mpAXIS_ERR_CAM_PARAMETER = -1064074722,
	mpAXIS_ERR_RECOVERY_NOT_ALLOWED = -1064074721,
} MpAxisErrorEnum;
#endif

#ifndef __AS__TYPE_MpComSeveritiesEnum
#define __AS__TYPE_MpComSeveritiesEnum
typedef enum MpComSeveritiesEnum
{	mpCOM_SEV_SUCCESS = 0,
	mpCOM_SEV_INFORMATIONAL = 1,
	mpCOM_SEV_WARNING = 2,
	mpCOM_SEV_ERROR = 3,
} MpComSeveritiesEnum;
#endif

#ifndef __AS__TYPE_MpAxisStatusIDType
#define __AS__TYPE_MpAxisStatusIDType
typedef struct MpAxisStatusIDType
{	MpAxisErrorEnum ID;
	MpComSeveritiesEnum Severity;
	unsigned short Code;
} MpAxisStatusIDType;
#endif

#ifndef __AS__TYPE_MpComFacilitiesEnum
#define __AS__TYPE_MpComFacilitiesEnum
typedef enum MpComFacilitiesEnum
{	mpCOM_FAC_UNDEFINED = -1,
	mpCOM_FAC_ARCORE = 0,
	mpCOM_FAC_SAFETY1 = 1,
	mpCOM_FAC_SAFETY2 = 2,
	mpCOM_FAC_GMC1 = 96,
	mpCOM_FAC_GMC2 = 97,
	mpCOM_FAC_GMCAXIS = 98,
	mpCOM_FAC_GMCAXESGROUP = 99,
	mpCOM_FAC_GMCARNCGROUP = 103,
	mpCOM_FAC_TRF = 105,
	mpCOM_FAC_MAPP_INTERNAL = 144,
	mpCOM_FAC_MAPP_CORE = 145,
	mpCOM_FAC_MAPP_INFRASTRUCTURE = 146,
	mpCOM_FAC_MAPP_MECHATRONIC = 147,
	mpCOM_FAC_MAPP_INDUSTRY = 148,
} MpComFacilitiesEnum;
#endif

#ifndef __AS__TYPE_MpAxisInternalType
#define __AS__TYPE_MpAxisInternalType
typedef struct MpAxisInternalType
{	signed long ID;
	MpComSeveritiesEnum Severity;
	MpComFacilitiesEnum Facility;
	unsigned short Code;
} MpAxisInternalType;
#endif

#ifndef __AS__TYPE_MpAxisExecutingCmdEnum
#define __AS__TYPE_MpAxisExecutingCmdEnum
typedef enum MpAxisExecutingCmdEnum
{	mpAXIS_CMD_IDLE = 0,
	mpAXIS_CMD_INIT = 1,
	mpAXIS_CMD_HOMING = 2,
	mpAXIS_CMD_STOP = 3,
	mpAXIS_CMD_HALT = 4,
	mpAXIS_CMD_MOVE_VELOCITY = 5,
	mpAXIS_CMD_MOVE_ABSOLUTE = 6,
	mpAXIS_CMD_GEAR_IN = 7,
	mpAXIS_CMD_GEAR_OUT = 8,
	mpAXIS_CMD_CAM_IN = 9,
	mpAXIS_CMD_CAM_OUT = 10,
	mpAXIS_CMD_DOWNLOAD_CAMS = 11,
	mpAXIS_CMD_MOVE_ADDITIVE = 12,
	mpAXIS_CMD_JOG_POSITIVE = 13,
	mpAXIS_CMD_JOG_NEGATIVE = 14,
	mpAXIS_CMD_STOP_PHASED = 15,
	mpAXIS_CMD_AUTOTUNE = 16,
	mpAXIS_CMD_REMOTE_CONTROL = 17,
	mpAXIS_CMD_MOVE_VEL_TRG_STOP = 18,
	mpAXIS_CMD_MOVE_ABS_TRG_STOP = 19,
	mpAXIS_CMD_MOVE_ADD_TRG_STOP = 20,
	mpAXIS_CMD_CAM_SEQUENCER = 50,
	mpAXIS_COUPLING_IDLE = 100,
	mpAXIS_CMD_PHASING = 101,
	mpAXIS_CMD_OFFSET = 102,
	mpAXIS_CMD_ABORT = 103,
	mpAXIS_CMD_UPDATE_GEAR = 104,
	mpAXIS_CMD_UPDATE_CAM = 105,
	mpAXIS_CMD_RECOVERY = 106,
	mpAXIS_CYCLIC_REF_IDLE = 200,
	mpAXIS_CMD_CYC_POSITION = 201,
	mpAXIS_CMD_CYC_VELOCITY = 202,
	mpAXIS_CMD_CYC_TORQUE = 203,
	mpAXIS_CMD_CYC_POSITION_UPDATE = 204,
	mpAXIS_CMD_CYC_VELOCITY_UPDATE = 205,
	mpAXIS_CMD_CYC_TORQUE_UPDATE = 206,
} MpAxisExecutingCmdEnum;
#endif

#ifndef __AS__TYPE_MpAxisDiagExtType
#define __AS__TYPE_MpAxisDiagExtType
typedef struct MpAxisDiagExtType
{	MpAxisStatusIDType StatusID;
	MpAxisInternalType Internal;
	MpAxisExecutingCmdEnum ExecutingCommand;
} MpAxisDiagExtType;
#endif

#ifndef __AS__TYPE_MpAxisBasicInfoType
#define __AS__TYPE_MpAxisBasicInfoType
typedef struct MpAxisBasicInfoType
{	plcbit AxisInitialized;
	plcbit ReadyToPowerOn;
	plcbit JogLimited;
	plcbit TorqueLimitActive;
	plcbit DriveRestarted;
	MpAxisCyclicReadType CyclicRead;
	MpAxisBootPhaseEnum BootState;
	MpAxisPlcOpenStateEnum PLCopenState;
	MpAxisDigitalIOStatusType DigitalInputsStatus;
	MpAxisAddInfoHardwareType HardwareInfo;
	MpAxisDiagExtType Diag;
	plcbit MoveDone;
} MpAxisBasicInfoType;
#endif

#ifndef __AS__TYPE_MC_0108_IS_TYP
#define __AS__TYPE_MC_0108_IS_TYP
typedef struct MC_0108_IS_TYP
{	plcbit Enable;
	plcbit Active;
	plcbit Error;
	plcbit Busy;
	unsigned short ErrorID;
	plcbit InputsSet;
	unsigned char cmdDigInForce;
	unsigned char state;
	unsigned char LockIDPar;
	plcbit oldHomeSwitch;
	plcbit oldPosHWSwitch;
	plcbit oldNegHWSwitch;
	plcbit oldTrigger1;
	plcbit oldTrigger2;
	unsigned char Reserve1;
} MC_0108_IS_TYP;
#endif

#ifndef __AS__TYPE_MpComIdentType
#define __AS__TYPE_MpComIdentType
typedef struct MpComIdentType
{	unsigned long Internal[2];
} MpComIdentType;
#endif

#ifndef __AS__TYPE_MpComInternalDataType
#define __AS__TYPE_MpComInternalDataType
typedef struct MpComInternalDataType
{	unsigned long pObject;
	unsigned long State;
} MpComInternalDataType;
#endif

struct MpAxisBasic
{	struct MpComIdentType(* MpLink);
	struct MpAxisBasicParType(* Parameters);
	unsigned long Axis;
	signed long StatusID;
	double Position;
	float Velocity;
	MpAxisBasicInfoType Info;
	MpComInternalDataType Internal;
	plcbit Enable;
	plcbit ErrorReset;
	plcbit Update;
	plcbit Power;
	plcbit Home;
	plcbit MoveVelocity;
	plcbit MoveAbsolute;
	plcbit MoveAdditive;
	plcbit Stop;
	plcbit JogPositive;
	plcbit JogNegative;
	plcbit Autotune;
	plcbit Simulate;
	plcbit TorqueLimit;
	plcbit ReleaseBrake;
	plcbit Active;
	plcbit Error;
	plcbit UpdateDone;
	plcbit CommandBusy;
	plcbit CommandAborted;
	plcbit PowerOn;
	plcbit IsHomed;
	plcbit InVelocity;
	plcbit InPosition;
	plcbit MoveActive;
	plcbit Stopped;
	plcbit TuningDone;
	plcbit Simulation;
	plcbit TorqueLimited;
	plcbit BrakeReleased;
};
_BUR_PUBLIC void MpAxisBasic(struct MpAxisBasic* inst);
struct MC_BR_SetHardwareInputs
{	unsigned long Axis;
	unsigned short ErrorID;
	unsigned long C_Axis;
	MC_0108_IS_TYP IS;
	plcbit Enable;
	plcbit HomeSwitch;
	plcbit PosHWSwitch;
	plcbit NegHWSwitch;
	plcbit Trigger1;
	plcbit Trigger2;
	plcbit Active;
	plcbit Busy;
	plcbit Error;
	plcbit InputsSet;
};
_BUR_PUBLIC void MC_BR_SetHardwareInputs(struct MC_BR_SetHardwareInputs* inst);
_BUR_LOCAL double iVa_OldRecPosition;
_BUR_LOCAL plcbit icmdErrorReset;
_BUR_LOCAL MpAxisBasicParType iBasicParamMaster;
_BUR_LOCAL AxisCtrl_typ iConCtrl;
_BUR_LOCAL struct MC_BR_SetHardwareInputs iVa_MasterInputs;
_BUR_LOCAL struct MpAxisBasic iFb_MasterAx;
_BUR_LOCAL AxStep_enum iAxStepMaster;
_BUR_LOCAL float PRODUCT_LENGTH;
_BUR_LOCAL float PER_SEC;
_BUR_LOCAL double PRINT_MARK_LIMIT;
_BUR_LOCAL double K_ZERO;
_BUR_LOCAL float iMI_ConSetSpeed;
_BUR_LOCAL float iMI_ConActSpeed;
_BUR_LOCAL float iMI_ConSetJogAcc;
_BUR_LOCAL float iMI_ConSetJogDeacc;
_BUR_LOCAL float iMI_ConSetJogVel;
_GLOBAL ACP10AXIS_typ gAxMaster;
_GLOBAL plcbit gIR_Trigger;
_GLOBAL MpComIdentType gmlMaster;
_LOCAL plcbit Edge0000100000;
_LOCAL plcbit Edge0000100001;
