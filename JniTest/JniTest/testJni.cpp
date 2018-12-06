#include "testing.h"
#include "priv_xay_ticketSystem_test_JniTest.h"
#include "priv_xay_ticketSystem_test_JniTest_Human.h"
#include <stdio.h>


JNIEXPORT jobjectArray JNICALL Java_priv_xay_ticketSystem_test_JniTest_objectTest
  (JNIEnv * env, jobject ojbc)
{
	jobjectArray humans=NULL;
	jclass human_class=NULL;
	jobject obj;
	jfieldID nameID;
	jfieldID ageID;
	jmethodID cons;
	jsize len;
	len=1;
	human_class=env->FindClass("Lpriv/xay/ticketSystem/test/Human;");	
	if(human_class==NULL)
		printf("class not found");
	humans=env->NewObjectArray(len,human_class,NULL);
	nameID=env->GetFieldID(human_class,"name","Ljava/lang/String;");
	ageID=env->GetFieldID(human_class,"age","I");
	cons=env->GetMethodID(human_class,"<init>","()V");
	obj=env->NewObject(human_class,cons);
	env->SetObjectField(obj,nameID,env->NewStringUTF("annie"));
	env->SetIntField(obj,ageID,(jint)19);
	env->SetObjectArrayElement(humans,0,obj);
	
	return humans;
}