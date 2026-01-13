#include <jni.h>
#include "ExpressionApp.h"
#include "../cpp/expression_engine.h"

ExpressionEngine engine;

extern "C" {

JNIEXPORT jdouble JNICALL
Java_ExpressionApp_evaluate(JNIEnv* env, jobject, jstring expr) {
    const char* cexpr = env->GetStringUTFChars(expr, nullptr);
    double result = engine.evaluate(cexpr);
    env->ReleaseStringUTFChars(expr, cexpr);
    return result;
}

}
