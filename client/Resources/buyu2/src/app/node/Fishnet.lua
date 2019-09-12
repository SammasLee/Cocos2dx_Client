local Fishnet = class("Fishnet", function()
    return cc.Node:create()
end)

function Fishnet:ctor(a)
  self:addWaterB()
  self:creat(a)
end
local fishnet1 = {}
for i = 1,3 do
  for j = 1,4 do
    if i == 3 and j >= 2 then
      break
    else
      local a = cc.rect((j-1)*290,(i-1)*242,290,242)
      table.insert(fishnet1,a)
    end
  end
end
local fishnet2 = {}
for i = 1,3 do
  for j = 1,4 do
    if i == 3 and j >= 2 then
      break
    else
      local a = cc.rect((j-1)*290,(i-1)*314,290,314)
      table.insert(fishnet2,a)
    end
  end
end
local fishnet3 = {}
for i = 1,3 do
  for j = 1,4 do
    if i == 3 and j >= 2 then
      break
    else
      local a = cc.rect((j-1)*360,(i-1)*360,360,360)
      table.insert(fishnet3,a)
    end
  end
end
local rectTab = {
  [2] = fishnet1,
  [3] = fishnet2,
  [4] = fishnet3,
}
local farmtab = {}
for i = 1,2 do
  for j = 1,7 do
    local a = cc.rect((j-1)*165.5,(i-1)*166,166,166)
    table.insert(farmtab,a)
  end
end
function Fishnet:creat(sum)
  self.sp = cc.Sprite:createWithSpriteFrameName(FishNetFrame[sum])
  self.sp:setAnchorPoint(cc.p(0.5,0.5))
  local fadein = cc.FadeIn:create(0.1)
  local anim = animateCache:getAnimation(FishNetAnim[sum])
  local action = cc.Animate:create(anim)
  local fadeout = cc.FadeOut:create(0.1)
  local function Endcallback(  )
    self:removeFromParent()
  end
  local funcall = cc.CallFunc:create(Endcallback)
  self.sp:runAction(cc.Sequence:create(fadein,action,fadeout,funcall))
  self:addChild(self.sp)
end
function Fishnet:addWaterB()

end
return Fishnet

