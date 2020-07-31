// miniprogram/pages/register/register.js
const db = wx.cloud.database();
Page({

  /**
   * 页面的初始数据
   */
  data: {
    username:"",
    password:""
  },

  inputUsername:function(e){
    this.setData({
      username: e.detail.value
    });
  },

  inputPassword:function(e){
    this.setData({
      password: e.detail.value
    });
  },

  register: function(e){
    //先要检查一下这个用户名是否被占用了
    db.collection('kehu').where({
      username:this.data.username
    }).get().then(res=>{
      if(res.data[0]!=null){
        wx.showToast({
          title:'用户名已被注册',
          icon:'none',
        })
        setTimeout(function () {
          wx.navigateBack({
            delta: 1
          })
        }, 2000);
      }
      else{
        db.collection("kehu").add({
          data: {
            username: this.data.username,
            password: this.data.password,
          }
        }).then(res=>{
          wx.showToast({
            title:'注册成功',
            icon:'success',
          }),
          setTimeout(function () {
            wx.navigateBack({
              delta: 1
            })
          }, 2000);
        }).catch(err=>{
          wx.showToast({
            title: '注册失败请重试',
            icon: 'none',
          })
        })
      }
    }).catch(err=>{
    });
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {

  },

  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady: function () {

  },

  /**
   * 生命周期函数--监听页面显示
   */
  onShow: function () {

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