--region NewFile_1.lua
--Author : Administrator
--Date   : 2017/4/8
--电磁炮管理类
local Dianci_Bullet_Manager = class("Dianci_Bullet_Manager",
 function()
	return cc.Node:create()
end
)
function Dianci_Bullet_Manager:ctor()
  cc.exports.g_Dianci_Bullet_Manager=self;
end
function Dianci_Bullet_Manager:GetBulletTotalNum()
 local childCount = self:getChildrenCount();
 return  childCount;
end
function Dianci_Bullet_Manager:Alive_Dianci_Bullet( bullet_id,  bullet_mulriple,  arm_mul,  arm_score,   chair_id,  StartPos,  angle)--
    self:removeChildByTag(bullet_id);
	local t_Dianci_Bullet = Dianci_Bullet.new(bullet_id, bullet_mulriple, arm_mul, arm_score, chair_id, StartPos, angle);
	self:addChild(t_Dianci_Bullet, 0, bullet_id);
end
function Dianci_Bullet_Manager:RemovAll()
  self:removeAllChildren();
end
function Dianci_Bullet_Manager:RemovbyId( bulletID)
self:removeChildByTag(bulletID);
end
return Dianci_Bullet_Manager;

--endregion
