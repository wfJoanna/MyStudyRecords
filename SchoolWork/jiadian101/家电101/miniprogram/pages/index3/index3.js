const db=wx.cloud.database();
var app = getApp();

// pages/talk/talk.js
Page({

  /**
   * 页面的初始数据
   */
  data: {
    textInputValue:'',
    chats:[],
    avatar:'',
    nickName:'',
    toname:'',
    choose:false,
    shangban:false,
  },

  choose:function(e){
    db.collection('kefu').doc('b887cea95f0682440000025f064901f0').update({
      data:{
        state:'咨询中',
        onhim:this.data.nickName,
      }
    }).then(res=>{
      this.setData({
        choose: true,
      })
      wx.showToast({
        title: '在咨询结束前，请不要退出登录',
        icon:'none'
      })
    }).catch(err=>{
    })
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad(options) {
    
  },
  
  onTextInput(e){
    this.setData({
      textInputValue:e.detail.value
    })
  },

  onSend(){
    if(!this.data.textInputValue){
      return
    }
    const doc={
      nickName:this.data.nickName,
      avatar:this.data.avatar,
      msgText:'text',
      textContent:this.data.textInputValue,
      sendTime:new Date(),
      sendTimeTS:Date.now(),
      toname:this.data.toname,
    }
    db.collection('chat').add({
      data:doc,
    })
    this.setData({
      textInputValue:'',
    })
  },
  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  async onReady(){
    db.collection('chat').watch({
      onChange:this.onChange.bind(this),
      onError(err){
        console.error(err)
      }
    })
  },
  onChange(snapshot){
    if(snapshot.type==='init'){
      this.setData({
        chats:[
          ...this.data.chats,
          ...[...snapshot.docs].sort((x,y)=>x.sendTimeTS-y.sendTimeTS)
        ],
      })
    }else{
      const chats=[...this.data.chats]
      for(const docChange of snapshot.docChanges){
        switch(docChange.queueType){
          case 'enqueue':
          chats.push(docChange.doc)
          break
        }
      }
      this.setData({
        chats:chats.sort((x,y)=>x.sendTimeTS-y.sendTimeTS)
      })
    }
  },
  /**
   * 生命周期函数--监听页面显示
   */
  onShow: function () {
    this.setData({
      nickName: app.globalData.globalName
    })
    db.collection('kefu').where({
      username:this.data.nickName,
    }).get().then(res=>{
      if(res.data[0]==null){
        this.setData({
          avatar:'/images/head2.png'
        })
      }
      else{
        this.setData({
          avatar:'/images/head1.png'
        })
      }
    });
    db.collection('kefu').where({
      username:'test2kefu',
    }).get({
      success: res => {
        // res.data 包含该记录的数据
        if(res.data[0].state=='可咨询'){
          this.setData({
            shangban: true
          })
        };
      }
    })
  },

  /**
   * 生命周期函数--监听页面隐藏
   */
  onHide: function () {

  },

  /**
   * 生命周期函数--监听页面卸载
   */
  onUnload: function () {

  },

  /**
   * 页面相关事件处理函数--监听用户下拉动作
   */
  onPullDownRefresh: function () {

  },

  /**
   * 页面上拉触底事件的处理函数
   */
  onReachBottom: function () {

  },

  /**
   * 用户点击右上角分享
   */
  onShareAppMessage: function () {

  }
})