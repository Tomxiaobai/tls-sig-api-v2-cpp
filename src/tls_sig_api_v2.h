#ifndef TLS_SIG_API_V2_H
#define TLS_SIG_API_V2_H

#if defined(WIN32) || defined(WIN64)
#pragma warning(disable: 4819)			// file codec warning, that's boring!
#define TLS_API __declspec(dllexport)
#else
#define TLS_API
#endif

#include <stdint.h>
#include <string>


/**
 * @brief ���� sig ���ݵĽṹ�壬�����ֶεĺ�����Բο� tls_gen_signature_ex()
 * @see tls_gen_signature_ex()
 */
typedef struct
{
	std::string strAccountType;
	std::string strAppid3Rd;
	std::string strAppid;            /**< �� sdkappid  */
	std::string strIdentify;
} SigInfo;

enum {
	CHECK_ERR1  =  1,       // sig Ϊ��
	CHECK_ERR2 ,            // sig base64 ����ʧ��
	CHECK_ERR3 ,            // sig zip ��ѹ��ʧ��
	CHECK_ERR4 ,            // sig ʹ�� json ����ʱʧ��
	CHECK_ERR5 ,            // sig ʹ�� json ����ʱʧ��
	CHECK_ERR6 ,            // sig �� json �� sig �ֶ� base64 ����ʧ��
	CHECK_ERR7 ,            // sig ���ֶ�ȱʧ
	CHECK_ERR8 ,            // sig У��ǩ��ʧ�ܣ�һ������Կ����ȷ
	CHECK_ERR9 ,            // sig ����
	CHECK_ERR10 ,           // sig ʹ�� json ����ʱʧ��
	CHECK_ERR11 ,           // sig �� appid_at_3rd �����Ĳ�ƥ��
	CHECK_ERR12 ,           // sig �� acctype �����Ĳ�ƥ��
	CHECK_ERR13 ,           // sig �� identifier �����Ĳ�ƥ��
	CHECK_ERR14 ,           // sig �� sdk_appid �����Ĳ�ƥ��
    CHECK_ERR15 ,           // sig �� userbuf �쳣
    CHECK_ERR16 ,           // �ڲ�����
    CHECK_ERR17 ,           // ǩ��ʧ�� ������˽Կ����

	CHECK_ERR_MAX,
};

/**
 * @brief ����ǩ������
 * @param sdkappid Ӧ��ID
 * @param identifier �û��˺ţ�utf-8 ����
 * @param key ��Կ
 * @param expire ��Ч�ڣ���λ��
 * @param sig ���ص� sig
 * @param errMsg ������Ϣ
 *
 * @return 0 Ϊ�ɹ����� 0 Ϊʧ��
 */
TLS_API int gen_sig(
        uint32_t sdkappid,
        const std::string& identifier,
		const std::string& key,
        int expire,
        std::string& sig,
        std::string& errMsg);

/**
 * @brief ���ɴ� userbuf ǩ������
 *
 * @param sdkappid Ӧ��ID
 * @param identifier �û��˺ţ�utf-8 ����
 * @param key ��Կ
 * @param expire ��Ч�ڣ���λ��
 * @param userBuf �û�����
 * @param sig ���ص� sig
 * @param errMsg ������Ϣ
 *
 * @return 0 Ϊ�ɹ����� 0 Ϊʧ��
 */
TLS_API int gen_sig_with_userbuf(
        uint32_t sdkappid,
        const std::string& identifier,
		const std::string& key,
        int expire,
        const std::string& userBuf,
        std::string& sig,
        std::string& errMsg);


int thread_setup();
void thread_cleanup();

namespace tls_signature_inner
{

TLS_API int SigToJson(const std::string &sig,
        std::string &json, std::string  &errmsg);

}

#endif

