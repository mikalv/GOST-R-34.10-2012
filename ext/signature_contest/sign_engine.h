/// @file
/// @brief ����������� ���������� �������, ���������� �� �������.
/// @copyright InfoTeCS. All rights reserved.

#ifndef CONTEST_SIGN_ENGINE_H
#define CONTEST_SIGN_ENGINE_H

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

typedef enum
{
     kStatusOk,
     kStatusWrongSignature,
     kStatusBadInput,
     kStatusInternalError
} Gost12S512Status;

/// @brief ������������� ������.
/// @return kStatusOk � ������ ��������� ����������.
/// @return kStatusInternalError � ������ ������
Gost12S512Status Gost12S512Init( );

/// @brief ���������� ������� ��������� ��� ��������� ����������� �������-512.
/// ��� �������, �������������� ������� ����� �����, �������� �� ���� � ������� LE. ��� ��������� ���������.
/// @param[in] privateKey �������� ���� �������.
/// @param[in] rand ��������� �����.
/// @param[in] hash ������������� ���.
/// @param[out] signature ��������������� ������� ���������.
/// @return kStatusOk � ������ ��������� ����������.
/// @return kStatusBadInput ������������ ������� ������.
/// @return kStatusInternalError � ��������� �������
Gost12S512Status Gost12S512Sign( const char* privateKey,
                                 const char* rand,
                                 const char* hash,
                                 char* signature );



/// @brief �������� ������������ ������� ��������� ��� ��������� ����������� �������-512.
/// ��� �������, �������������� ������� ����� �����, �������� �� ���� � ������� LE. ��� ��������� ���������.
/// @param[in] publicKeyX ����� X ��������� ����� �������.
/// @param[in] publicKey� ����� Y ��������� ����� �������.
/// @param[in] hash ��� ������������ ���������.
/// @param[in] signature �������.
/// @return kStatusOk � ������ ��������� ����������.
/// @return kStatusWrongSignature ������� �� ������������� ��������� ���������.
/// @return kStatusBadInput ������������ ������� ������.
/// @return kStatusInternalError � ��������� �������.
Gost12S512Status Gost12S512Verify( const char* publicKeyX,
                                   const char* publicKeyY,
                                   const char* hash,
                                   const char* signature );


#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CONTEST_SIGN_ENGINE_H
