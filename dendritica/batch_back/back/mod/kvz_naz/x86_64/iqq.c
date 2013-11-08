/* Created by Language version: 6.2.0 */
/* NOT VECTORIZED */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "scoplib.h"
#undef PI
 
#include "md1redef.h"
#include "section.h"
#include "md2redef.h"

#if METHOD3
extern int _method3;
#endif

#undef exp
#define exp hoc_Exp
extern double hoc_Exp();
 
#define _threadargscomma_ /**/
#define _threadargs_ /**/
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 static double *_p; static Datum *_ppvar;
 
#define t nrn_threads->_t
#define dt nrn_threads->_dt
#define gqbar _p[0]
#define Iqq _p[1]
#define qq _p[2]
#define Dqq _p[3]
#define _g _p[4]
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 static int hoc_nrnpointerindex =  -1;
 /* external NEURON variables */
 extern double celsius;
 /* declaration of user functions */
 static int _hoc_alp();
 static int _hoc_bet();
 static int _hoc_rate();
 static int _hoc_state();
 static int _mechtype;
extern int nrn_get_mechtype();
 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _p = _prop->param; _ppvar = _prop->dparam;
 }
 static _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range();
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 ret(1.);
}
 /* connect user functions to hoc names */
 static IntFunc hoc_intfunc[] = {
 "setdata_qq", _hoc_setdata,
 "alp_qq", _hoc_alp,
 "bet_qq", _hoc_bet,
 "rate_qq", _hoc_rate,
 "state_qq", _hoc_state,
 0, 0
};
#define alp alp_qq
#define bet bet_qq
 extern double alp();
 extern double bet();
 /* declare global and static user variables */
#define a0 a0_qq
 double a0 = 0.00057;
#define b0 b0_qq
 double b0 = 0.00057;
#define erevq erevq_qq
 double erevq = -35;
#define gq gq_qq
 double gq = 0.4;
#define inf inf_qq
 double inf = 0;
#define qten qten_qq
 double qten = 5;
#define tau tau_qq
 double tau = 0;
#define vhalf vhalf_qq
 double vhalf = -88;
#define zeta zeta_qq
 double zeta = 3;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "erevq_qq", "mV",
 "vhalf_qq", "mV",
 "a0_qq", "/ms",
 "b0_qq", "/ms",
 "zeta_qq", "1",
 "gq_qq", "1",
 "qten_qq", "1",
 "gqbar_qq", "mho/cm2",
 "Iqq_qq", "mA/cm2",
 0,0
};
 static double delta_t = 1;
 static double qq0 = 0;
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "erevq_qq", &erevq_qq,
 "vhalf_qq", &vhalf_qq,
 "a0_qq", &a0_qq,
 "b0_qq", &b0_qq,
 "zeta_qq", &zeta_qq,
 "gq_qq", &gq_qq,
 "qten_qq", &qten_qq,
 "inf_qq", &inf_qq,
 "tau_qq", &tau_qq,
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(), nrn_init(), nrn_state();
 static void nrn_cur(), nrn_jacob();
 
static int _ode_count();
 /* connect range variables in _p that hoc is supposed to know about */
 static char *_mechanism[] = {
 "6.2.0",
"qq",
 "gqbar_qq",
 0,
 "Iqq_qq",
 0,
 "qq_qq",
 0,
 0};
 
static void nrn_alloc(_prop)
	Prop *_prop;
{
	Prop *prop_ion, *need_memb();
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 5, _prop);
 	/*initialize range parameters*/
 	gqbar = 0.003;
 	_prop->param = _p;
 	_prop->param_size = 5;
 
}
 static _initlists();
 _iqq_reg() {
	int _vectorized = 0;
  _initlists();
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 0);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
  hoc_register_dparam_size(_mechtype, 0);
 	hoc_register_cvode(_mechtype, _ode_count, 0, 0, 0);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 qq /Users/boris/git/l5pyr/dendritica/batch_back/back/mod/kvz_naz/x86_64/iqq.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 static double _zfacq ;
static int _reset;
static char *modelname = "Q current";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static _modl_cleanup(){ _match_recurse=1;}
static rate();
static state();
 
double alp (  _lv )  
	double _lv ;
 {
   double _lalp;
 _lalp = exp ( 1.e-3 * zeta * ( _lv - vhalf ) * 9.648e4 / ( 8.315 * ( 273.16 + celsius ) ) ) ;
   
return _lalp;
 }
 
static int _hoc_alp() {
  double _r;
   _r =  alp (  *getarg(1) ) ;
 ret(_r);
}
 
double bet (  _lv )  
	double _lv ;
 {
   double _lbet;
 _lbet = exp ( 1.e-3 * zeta * gq * ( _lv - vhalf ) * 9.648e4 / ( 8.315 * ( 273.16 + celsius ) ) ) ;
   
return _lbet;
 }
 
static int _hoc_bet() {
  double _r;
   _r =  bet (  *getarg(1) ) ;
 ret(_r);
}
 
static int  state (  )  {
   rate ( _threadargscomma_ v ) ;
   qq = qq + _zfacq * ( inf - qq ) ;
   
/*VERBATIM*/
        return 0;
  return 0; }
 
static int _hoc_state() {
  double _r;
   _r = 1.;
 state (  ) ;
 ret(_r);
}
 
static int  rate (  _lv )  
	double _lv ;
 {
   double _la , _lq10 ;
 _lq10 = pow( qten , ( ( celsius - 23.0 ) / 10.0 ) ) ;
   _la = alp ( _threadargscomma_ _lv ) ;
   inf = 1.0 / ( 1.0 + _la ) ;
   tau = bet ( _threadargscomma_ _lv ) / ( _lq10 * ( a0 + b0 * _la ) ) ;
   if ( tau < 2.0 ) {
     tau = 10.0 ;
     }
   _zfacq = pow( ( 1.0 - exp ( - dt / tau ) ) , 1.2 ) ;
    return 0; }
 
static int _hoc_rate() {
  double _r;
   _r = 1.;
 rate (  *getarg(1) ) ;
 ret(_r);
}
 
static int _ode_count(_type)int _type; { hoc_execerror("qq", "cannot be used with CVODE");}

static void initmodel() {
  int _i; double _save;_ninits++;
 _save = t;
 t = 0.0;
{
  qq = qq0;
 {
   rate ( _threadargscomma_ v ) ;
   qq = inf ;
   }
  _sav_indep = t; t = _save;

}
}

static void nrn_init(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
 initmodel();
}}

static double _nrn_current(double _v){double _current=0.;v=_v;{ {
   Iqq = gqbar * qq * ( v - erevq ) ;
   }
 _current += Iqq;

} return _current;
}

static void nrn_cur(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 _g = _nrn_current(_v + .001);
 	{ _rhs = _nrn_current(_v);
 	}
 _g = (_g - _rhs)/.001;
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
  }
 
}}

static void nrn_jacob(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) += _g;
  }else
#endif
  {
     _nd = _ml->_nodelist[_iml];
	NODED(_nd) += _g;
  }
 
}}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type){
 double _break, _save;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 _break = t + .5*dt; _save = t;
 v=_v;
{
 { {
 for (; t < _break; t += dt) {
 error =  state();
 if(error){fprintf(stderr,"at line 51 in file iqq.mod:\n	SOLVE state\n"); nrn_complain(_p); abort_run(error);}
 
}}
 t = _save;
 }}}

}

static terminal(){}

static _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
_first = 0;
}
