#include "Camera.h"
#include "Struct.h"
#include "HHelper.h"
#include "DirectXBase.h"
#include <d3d12.h>
#include "Input.h"

Camera::Camera() {
	eye = XMFLOAT3(0, 0, 0);		//���_���W		�Q�[�����[���h���ł̃J�������W
	target = XMFLOAT3(0, 0, 0);		//�����_���W		�Q�[�����[���h���ŃJ���������Ă�����W
	up = XMFLOAT3(0, 1, 0);											//������x�N�g��	�Q�[�����[���h���ŃJ�������猩�ď�������w���x�N�g��
	//matView = XMMatrixLookAtLH(eye.ConvertXMVECTOR(), target.ConvertXMVECTOR(), up.ConvertXMVECTOR());
	//XMStoreFloat3(&(forwardVec), XMVector3Normalize(XMLoadFloat3(&forwardVec)));
	angleOfView = 60.0f;
}

void Camera::GenerateMatView()
{
	matView = XMMatrixLookAtLH(eye.ConvertXMVECTOR(), target.ConvertXMVECTOR(), up.ConvertXMVECTOR());
	//�������e�ϊ��s��
	matPerspective = XMMatrixPerspectiveFovLH(
		XMConvertToRadians(60.0f),				//��p(60�x)
		(float)window_width / window_height,	//�A�X�y�N�g��
		0.1f, 1000000.0f							//�O�[�A���[
	);
	//�ˉe�ϊ��s��
	matProjection = XMMatrixOrthographicOffCenterLH(0, window_width, window_height, 0, 0.01f, 100000.0f);
}

void Camera::Init()
{
	eye = Vec3(0, 5, 10);
	target = Vec3(0, 0, 0);
	up = Vec3(0, 1, 0);
	rotationMat = XMMatrixIdentity();
	upRotationMat = XMMatrixIdentity();
	matView = XMMatrixLookAtLH(eye.ConvertXMVECTOR(), target.ConvertXMVECTOR(), up.ConvertXMVECTOR());
	matPerspective = {};
	matProjection = {};
	Camera::angleOfView = 60;
	angleXZ = 0;
	forwardVec = Vec3{ 0,0,1 };

}

void Camera::Update()
{

	forwardVec.x = cosf(angleXZ);
	forwardVec.z = sinf(angleXZ);


	// ���_�����E�𒴂��Ȃ��悤�ɂ���B
	if (1.0f < forwardVec.y) forwardVec.y = 1.0f;
	if (forwardVec.y < -1.0f) forwardVec.y = -1.0f;

	// ���_���W���王�_�_���W�����߂�B
	const float EYE_TARGET = 100.0f;
	target = eye + forwardVec * EYE_TARGET;

	// ��x�N�g�������߂�B


}

void Camera::AddRotation(const float& RotX, const float& RotY, const float& RotZ)
{

	// �J�����̉�]�s�����]������B
	DirectX::XMMATRIX buff = DirectX::XMMatrixIdentity();
	buff *= XMMatrixRotationZ(RotZ);
	buff *= XMMatrixRotationX(RotX);
	buff *= XMMatrixRotationY(RotY);

	rotationMat = buff * rotationMat;

}

void Camera::AddRotationXZ(const float& Rot)
{

	angleXZ += Rot;

}

void Camera::Move(const float& Speed)
{
	Vec3 forwardVecBuff = forwardVec;
	forwardVecBuff.y = 0;
	eye += forwardVecBuff * Speed;

}

Vec3 Camera::GetEyeVector()
{
	XMFLOAT3 returnBuff = HHelper::Normalize3D(XMFLOAT3(honraiTarget.x - honraiEye.x, honraiTarget.y - honraiEye.y, honraiTarget.z - honraiEye.z));
	return returnBuff;
}