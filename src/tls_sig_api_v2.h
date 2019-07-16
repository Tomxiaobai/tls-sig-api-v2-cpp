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

enum {
    CHECK_ERR01 = 1,       // sig Ϊ��
    CHECK_ERR02,           // sig base64 ����ʧ��
    CHECK_ERR03,           // sig zip ��ѹ��ʧ��
    CHECK_ERR04,           // sig ʹ�� json ����ʱʧ��
    CHECK_ERR05,           // sig ʹ�� json ����ʱʧ��
    CHECK_ERR06,           // sig �� json �� sig �ֶ� base64 ����ʧ��
    CHECK_ERR07,           // sig ���ֶ�ȱʧ
    CHECK_ERR08,           // sig У��ǩ��ʧ�ܣ�һ������Կ����ȷ
    CHECK_ERR09,           // sig ����
    CHECK_ERR10,           // sig ʹ�� json ����ʱʧ��
    CHECK_ERR11,           // sig �� appid_at_3rd �����Ĳ�ƥ��
    CHECK_ERR12,           // sig �� acctype �����Ĳ�ƥ��
    CHECK_ERR13,           // sig �� identifier �����Ĳ�ƥ��
    CHECK_ERR14,           // sig �� sdk_appid �����Ĳ�ƥ��
    CHECK_ERR15,           // sig �� userbuf �쳣
    CHECK_ERR16,           // �ڲ�����
    CHECK_ERR17,           // ǩ��ʧ�� ������˽Կ����
    CHECK_ERR_MAX,
};


/**
 * @brief ����ǩ������
 * @param sdkappid Ӧ��ID
 * @param identifier �û��˺ţ�utf-8 ����
 * @param key ��Կ
 * @param expire ��Ч�ڣ���λ��
 * @param sig ���ص� sig
 * @param errmsg ������Ϣ
 *
 * @return 0 Ϊ�ɹ����� 0 Ϊʧ��
 */
TLS_API int gen_sig(
        uint32_t sdkappid,
        const std::string& identifier,
        const std::string& key,
        int expire,
        std::string& sig,
        std::string& errmsg);


/**
 * @brief ���ɴ� userbuf ǩ������
 *
 * @param sdkappid Ӧ��ID
 * @param identifier �û��˺ţ�utf-8 ����
 * @param key ��Կ
 * @param expire ��Ч�ڣ���λ��
 * @param userbuf �û�����
 * @param sig ���ص� sig
 * @param errmsg ������Ϣ
 *
 * @return 0 Ϊ�ɹ����� 0 Ϊʧ��
 */
TLS_API int gen_sig_with_userbuf(
        uint32_t sdkappid,
        const std::string& identifier,
        const std::string& key,
        int expire,
        const std::string& userbuf,
        std::string& sig,
        std::string& errmsg);


int thread_setup();
void thread_cleanup();

#endif // TLS_SIG_API_V2_H
