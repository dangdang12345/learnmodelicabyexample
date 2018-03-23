/***********************************************************
*	momodel.c                                                   
*                                                           
*	  �����������ģ�������ļ��������init.txt, para.mat      
*	��setting.txt�ļ��������ʵ��������ģ����⡣             
*                                                           
*	  ���ļ���MWorks����������CodeGenerator�Զ����ɡ�         
*                                                           
*	  ģ�����ƣ�NewtonCooling
*	  ����ʱ�䣺2017-03-15 08:27:32
*                                                           
*	  ����ͬԪ�����Ϣ�������޹�˾                            
*	           2005-2017
*                                                           
***********************************************************/

#include "model_block1.h"


#include "momodel_types.h"

MWS_MO_SECTION_NMPL_BEGIN(StructSection)
MWS_MO_SECTION_NMPL_END

MWS_MO_SECTION_BEGIN(ConstantSection)
MWS_MO_SECTION_END

MWS_MO_SECTION_BEGIN(ParameterSection)
    R_[1] = 298.15;
    R_[2] = 363.15;
    R_[3] = 0.7;
    R_[4] = 1.0;
    R_[5] = 0.1;
    R_[6] = 1.2;
MWS_MO_SECTION_END

MWS_MO_SECTION_BEGIN(DependingSection)
MWS_MO_SECTION_END

MWS_MO_SECTION_BEGIN(InitialSection)
    R_[7] = R_[2];
MWS_MO_SECTION_END

MWS_MO_SECTION_BEGIN(ReinitSection)
MWS_MO_SECTION_END

MWS_MO_SECTION_BEGIN(DynamicSectionDP)
    /* �������Է��� (2, 0) */
    BEGIN_LINEAR_BLOCK(1)
    MoReal A[1] = {0};
    MoReal b[1] = {0};
    const char* const varname[] = {
        "der(T)", 
    0};
    x[0] = R_[8];
    b[0] = ((R_[3] * R_[4]) * (R_[1] + ((-1) * R_[7])));
    A[0] = (R_[5] * R_[6]);
    SolveTrivialLinear(A, "A", b, "b", x, varname, 2);
    CheckReturnValue();
    R_[8] = x[0];
    END_LINEAR_BLOCK

MWS_MO_SECTION_END

MWS_MO_SECTION_BEGIN(DynamicSectionDI)
MWS_MO_SECTION_END

MWS_MO_SECTION_BEGIN(DynamicSectionDN)
MWS_MO_SECTION_END

MWS_MO_SECTION_BEGIN(DynamicSectionEP)
MWS_MO_SECTION_END

MWS_MO_SECTION_BEGIN(DynamicSectionEI)
MWS_MO_SECTION_END

MWS_MO_SECTION_BEGIN(DynamicSectionEN)
MWS_MO_SECTION_END

MWS_MO_SECTION_BEGIN(DynamicSectionIP)
MWS_MO_SECTION_END

MWS_MO_SECTION_BEGIN(DynamicSectionII)
MWS_MO_SECTION_END

MWS_MO_SECTION_BEGIN(DynamicSectionIN)
MWS_MO_SECTION_END

MWS_MO_SECTION_BEGIN(DummySection)
MWS_MO_SECTION_END

MWS_MO_SECTION_NMPL_BEGIN(StateSection)
    MWS_DECL_STATE("T",1,7,8,1);
MWS_MO_SECTION_NMPL_END

MWS_MO_SECTION_NMPL_BEGIN(PreSection)
MWS_MO_SECTION_NMPL_END

MWS_MO_SECTION_NMPL_BEGIN(EvalSection)
MWS_MO_SECTION_NMPL_END

MWS_BASE_PATH_MAP_BEGIN
    MWS_BASE_PATH_MAP_ITEM(">root<","");
MWS_BASE_PATH_MAP_END

MWS_MO_SECTION_NMPL_BEGIN(TotalSection)
    MoInteger sz1[] = {8,0,0,0,1,0,0};
    MoInteger sz2[] = {0,0,0,0,0};
    MoInteger sz3[] = {0,0,0,0,0,0,1};
    MoInteger sz4[] = {1,0,0,0,0};
    MWS_MODEL_TOTAL(sz1,sz2,sz3,sz4,model_guid);
MWS_MO_SECTION_NMPL_END

MWS_JACGCP_INFO_BEGIN()
MWS_JACGCP_INFO_END

MWS_EXTERNAL_INFO_BEGIN()
MWS_EXTERNAL_INFO_END


