#include "Java_C.h"


extern "C" {
	 void Java_org_cocos2dx_cpp_AppActivity_cocosExitGame() {   
		Director::getInstance()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
		exit(0);  
#endif
	}
}

bool Java_C::getStaticMethodInfo(const char* className,const char *  methodName, const char* paramCode) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		JniMethodInfo methodInfo;
		//auto isOk = JniHelper::getStaticMethodInfo(methodInfo, "org/cocos2dx/cpp/AppActivity", str, "()V");
		auto isOk = JniHelper::getStaticMethodInfo(methodInfo, className,methodName, paramCode);
		if (isOk)
		{
			auto activityObj = methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID);
		}
		return isOk;
#else
	return false;
#endif
}


