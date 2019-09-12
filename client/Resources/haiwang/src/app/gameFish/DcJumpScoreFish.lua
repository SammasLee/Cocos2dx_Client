--region NewFile_1.lua
--Author : Administrator
--Date   : 2017/4/24
--此文件由[BabeLua]插件自动生成
local DcJumpScoreFish = class("DcJumpScoreFish",cc.exports.Fish)
function DcJumpScoreFish:ctor( fish_kind,  fish_id,  fish_multiple,  fish_speed,  bounding_box_width,  bounding_box_height,  hit_radius,  startPos,  delay)

        bounding_box_width=580;
        bounding_box_height=360;
        fish_multiple = 100;
        DcJumpScoreFish.super.ctor(self,fish_kind,  fish_id,  fish_multiple,  fish_speed,  bounding_box_width,  bounding_box_height,  hit_radius,  startPos,  delay);
        if (self.fis_node) then 
           self.baseAngle =math.rad(90);
           	local file_name ="";
			local _sprite = nil;
			local readIndex = 0;
			local animation = cc.Animation:create();
            local i=0;
			for  i = 0,50, 1 do
                file_name=string.format("~MRY_000_%03d.png", i);
				local frame =cc.SpriteFrameCache:getInstance():getSpriteFrame(file_name);
				if (frame) then									
						if (cc.exports.g_offsetmap_InitFlag[23]<1) then       
                            local offset_name=string.format("MRY_000_%03d.png", i);
							local t_offset_ = cc.p(0, 0);
                            local t_offect_str=cc.exports.OffsetPointMap[offset_name].Offset;
                            local t_s_sub_x,t_s_sub_y=string.find(t_offect_str, ",");
                            local t_x=string.sub(t_offect_str, 0,t_s_sub_x-1);
                            local t_y=string.sub(t_offect_str, t_s_sub_y+1,#t_offect_str);
                            local t_offeset_pos=cc.p(0,0);
                            local t_offset_0 = frame:getOffsetInPixels();
                            --cclog("DcJumpScoreFish:ctor t_offset_0[%d](%f,%f) t_offset_(%f,%f)", i,t_offset_0.x,t_offset_0.y,t_x,t_y);
                            t_offset_.x =t_x*0.65;--/2;--t_offset_.x * 10/ 20;
		 	                t_offset_.y =-t_y*0.65;--/2;--t_offset_.y * 10/ 20;   
                           frame:setOffsetInPixels(t_offset_);
					end
					if (readIndex == 0)then 	_sprite=cc.Sprite:createWithSpriteFrame(frame) ;end
					readIndex=readIndex+1;    
                   animation:addSpriteFrame(frame);
				end
            end --for
            if (readIndex > 0)	then 
                  cc.exports.g_offsetmap_InitFlag[23]=1;
			      animation:setDelayPerUnit(1/12.0);
				  local action =cc.Animate:create(animation);   
				  _sprite:runAction(cc.RepeatForever:create(action));
                  self.fis_node:addChild(_sprite, 0, 10086);
			end
        end
end
function DcJumpScoreFish:CatchFish( chair_id,  score,  bulet_mul,  fish_mul,  bomFlag)
     cc.exports.g_soundManager:PlayGameEffect("ScoreStartJump");
	self.m_mov_timer = 0;
	self.m_catch_chairID = chair_id;
	self.m_catch_mul = fish_mul;
	self.m_catch_bullet_mul = bulet_mul;
	self.m_catch_score = score;
	self.fish_status_ = 2;
    self.alive_limi_time=0;
    self.alive_limi_time=0;
    if (bomFlag>0) then 
		if (self.m_catch_score > 0) then 	
			local t_ScoreAnimation=ScoreAnimation.new(self:GetFishccpPos(),self.fish_multiple_, self.m_catch_chairID, self.m_catch_score);
            cc.exports.game_manager_:addChild(t_ScoreAnimation, 112);
		    cc.exports.g_CoinManager:BuildCoin(self:GetFishccpPos(), self.m_catch_chairID, self.m_catch_score, self.fish_multiple_);
		end
		self.m_fish_die_action_EndFlag = 1;
		return;
	end
    if (self.fis_node:getChildByTag(8888)) then self.fis_node:removeChildByTag(8888); end
	self:setLocalZOrder(15);
    cc.exports.g_soundManager:PlayFishEffect(self.fish_kind_);
	local  t__local_info_type = _local_info_array_[chair_id];
    if (self.fis_node) then 
        self.fis_node:removeAllChildren();
        self.baseAngle = math.rad(90);
        -- //播放特效
		--My_Particle_manager::GetInstance()->PlayParticle(0, fis_node->getPosition());
         cc.exports.g_My_Particle_manager:PlayParticle(0, self:GetFishccpPos());
		 cc.exports.game_manager_:ShakeScreen();
         	local file_name ="";
             local offset_name="";
			local _sprite = nil;
			local readIndex = 0;
			local animation = cc.Animation:create();
            local i=0;
            local  get_full_flag=0;     
			for  i = 0,50, 1 do          
                --if(get_full_flag>0) then  file_name=string.format("~MRY_001_%03d.png", i); 
                --else
                file_name=string.format("~MRY_000_%03d.png", i);  --end
				local frame =cc.SpriteFrameCache:getInstance():getSpriteFrame(file_name);
				if (frame) then										
						if (cc.exports.g_offsetmap_InitFlag_D[23]<1) then -- and get_full_flag>0
                             local offset_name=string.format("MRY_000_%03d.png", i);
							local t_offset_ = cc.p(0, 0);
                            local t_offect_str=cc.exports.OffsetPointMap[offset_name].Offset;
                            local t_s_sub_x,t_s_sub_y=string.find(t_offect_str, ",");
                            local t_x=string.sub(t_offect_str, 0,t_s_sub_x-1);
                            local t_y=string.sub(t_offect_str, t_s_sub_y+1,#t_offect_str);
                            local t_offeset_pos=cc.p(0,0);
                            local t_offset_0 = frame:getOffsetInPixels();
                            t_offset_.x =t_x*0.65;--t_offset_.x * 10/ 20;
		 	                t_offset_.y = -t_y*0.65;--t_offset_.y * 10/ 20;   
                           frame:setOffsetInPixels(t_offset_);
                           cc.exports.g_offsetCoin_InitFlag[i]=1;
					end
					if (readIndex == 0)then 	_sprite=cc.Sprite:createWithSpriteFrameName(file_name) ;end
					readIndex=readIndex+1;    
                   animation:addSpriteFrame(frame);
				end
            end --for
            if (readIndex > 0)	then 
                  cc.exports.g_offsetmap_InitFlag_D[23]=1;
			      animation:setDelayPerUnit(1/24.0);
				  local action =cc.Animate:create(animation);   
				  _sprite:runAction(cc.RepeatForever:create(action));
                  self.fis_node:addChild(_sprite, 0, 10086);
			end		
           local x,y=self.fis_node:getPosition();
           cc.exports.g_cannon_manager:Catch_MRYCarb(self.m_catch_chairID, self:fish_id(), cc.p(x,y), self.m_catch_score, self.m_catch_bullet_mul);
    end
end
function DcJumpScoreFish:CatchEnd()
    --cclog("DcJumpScoreFish:CatchEnd");
    self.m_fish_die_action_EndFlag = 1;
	--通知UI 结束
	local t_Score =cc.exports.g_cannon_manager:GetMRY_Catch_Score(self.m_catch_chairID);
	if (t_Score > 0)then

	 local t_ScoreAnimation=ScoreAnimation.new(self:GetFishccpPos(),self.fish_multiple_, self.m_catch_chairID, t_Score);
         cc.exports.game_manager_:addChild(t_ScoreAnimation, 112);
		 cc.exports.g_CoinManager:BuildCoin(self:GetFishccpPos(), self.m_catch_chairID, t_Score, self.fish_multiple_);
	end
end
function  DcJumpScoreFish:OnFrame(delta_time)
   --cclog(" Fish:OnFrame dt=%f",dt);
    --if(delta_time>0.04) then delta_time=0.04; end;
   if (self.active_==0) then return false;end
   if (self.fish_status_ == 0) then
   	    self.trace_index_ = 0;
	    self.m_nFishDieCount=0;
		self.fish_status_ = 1;
        if (self.m_moveKind == 0) then 
           local fish_trace = self.trace_vector_[self.trace_index_];
           self.m_mov_position=cc.p(fish_trace.x, fish_trace.y);
           self.fis_node:setPosition(cc.p(fish_trace.x, fish_trace.y));		
        end
        --self.fis_node:setVisible(t);
   end
   if (self.fish_status_ == 1)  then
        self.alive_limi_time= self.alive_limi_time+delta_time;
        if(self.alive_limi_time>70) then return  true ;end 
       if (self.m_mov_delay_timer > 0.0001) then 
			self.m_mov_delay_timer=self.m_mov_delay_timer-delta_time;
			return false;
		end
         self:ChainLindFishUpdate(delta_time);
         if (self.m_connect_Stop_Flag == 0) then 
             --按原路径移动
             if (self.m_moveKind < 2) then 
              self.check_timer=self.check_timer+delta_time;
              if(  self.check_timer>0.15) then 
                 self.check_timer=0;
				  self:CheckValid();    
                end                   
                 self.m_mov_timer= self.m_mov_timer+delta_time;-- end
                 if ( self.m_mov_timer > 0.0333) then 
                     local  Mov_Step =1
                     self.m_mov_timer = self.m_mov_timer -0.0333
                      if (self.m_mov_timer > 0.0333) then
                           self.m_mov_timer = 0;		
                      end
                     if (self.stop_count_ > 0 and  self.trace_index_ == self.stop_index_ and self.current_stop_count_ < self.stop_count_) then
						      self.current_stop_count_ = self.current_stop_count_+Mov_Step;
						     if (self.current_stop_count_ >= self.stop_count_) then self:SetFishStop(0, 0);end
                       elseif (self.m_fish_mov_by_actionFlag == 0) then 			
                            self.trace_index_ = self.trace_index_ +Mov_Step;
							--if (self.m_moveKind == 0)  then self.trace_index_ = self.trace_index_ +Mov_Step;
							--else			               self.trace_index_ = self.trace_index_ +(self.fish_speed_*Mov_Step);	end
						    if (self.trace_index_ >= #self.trace_vector_-2)  then return true;
                            else
							    local  fish_trace = self.trace_vector_[self.trace_index_];
							    self.show_angle = fish_trace[3] - self.baseAngle;
						    	self.m_fish_Check_Angle = self.show_angle;
						     	if (self.fis_node) then 
							        	local rotation = self.show_angle*57.29577951308
					                   self.fis_node:setRotation(rotation)
					                   self.fis_node:setPosition(cc.p(fish_trace[1], fish_trace[2]))
                                       self.m_mov_position=cc.p(fish_trace[1], fish_trace[2]);
								       --if (self.fis_node:isVisible()==false) then self.fis_node:setVisible(true); end
							end--if (self.fis_node) then 
						  end--if (self.trace_index_ >= #self.trace_vector_)  then return true;
					    end --   elseif (self.m_fish_mov_by_actionFlag == 0) then 			
					end  -- if ( self.m_mov_timer > 0.0333) then 
              else   -- if (self.m_moveKind >2) then 
               --if(self.scene_fish_flag==0) then 
               --   if(self.alive_limi_time>30) then return  true end;
               --else 
                if(self.alive_limi_time>60) then return  true end;
               --end
               if(self:Mov_by_List(delta_time)==true) then return  true ;end  --新的路径移动
              end
         end
   else 
       if (self.m_fish_die_action_EndFlag>0) then return true; end
--		self.m_mov_timer=self.m_mov_timer+delta_time;
--		if(self.m_mov_timer>0.033) then --30fps
--			self.m_mov_timer=self.m_mov_timer-0.033;
--			self.m_nFishDieCount=self.m_nFishDieCount+1;
--			if(self.m_nFishDieCount>180) then return true; end
--		end
   end
   return false;
end
function DcJumpScoreFish:Reset_JumScore( ChairID)
end
return DcJumpScoreFish;
--endregion
