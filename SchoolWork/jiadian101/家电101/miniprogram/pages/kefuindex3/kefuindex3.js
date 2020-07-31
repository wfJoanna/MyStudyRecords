// miniprogram/pages/kefuindex3/kefuindex3.js
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
    shangban:false,
    onhim:'',
    word:['您好，请问有什么需要帮助的吗？','您的订单是什么时候提交的呢？','好的，请稍等','正在为您查询订单'],
  },

  pick:function(e){
    this.setData({
      textInputValue:this.data.word[e.detail.value],
    })
  },

  qingchu:function(e){
    var that= this;
    wx.showModal({
      title: '提示',
      content: '确认结束吗？',
      success (res) {
        if (res.confirm) {
          wx.cloud.callFunction({
            name:'qingchu',
            data:{
              nname:that.data.onhim,
            }
          }).then(res=>{
            db.collection('kefu').doc('b887cea95f0682440000025f064901f0').update({
              data:{
                state:'可咨询',
                onhim:'',
              }
            })
            wx.showToast({
              title:'成功结束',
            });
            setTimeout(function () {
              wx.navigateBack({
                delta: 1
              })
            }, 2000);
          }).catch(err=>{
            wx.showToast({
              title:'结束失败请重试',
              icon:'none',
            })
          });
        } else if (res.cancel) {
        }
      }
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
        this.setData({
          onhim:res.data[0].onhim
        })
        if(res.data[0].state=='咨询中'){
          this.setData({
            shangban: true
          })
          wx.showToast({
            title:'当前客户在咨询',
            icon:'none',
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