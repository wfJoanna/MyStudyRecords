// miniprogram/pages/pingjia/pingjia.js
const db = wx.cloud.database();
Page({

  /**
   * 页面的初始数据
   */
  data: {
    radioItems: [
      {name: '1',},
      {name: '2'},
      {name: '3'},
      {name: '4'},
      {name: '5',checked: 'true'}
    ],
    flag: '5',
    id:'',
    pingj:5,
  },

  radioChange:function(e){
    this.setData({
      flag: e.detail.value
    })
  },

  queding:function(e){
    if(this.data.flag=='1'){
      this.setData({
        pingj:1
      })
    }
    else if(this.data.flag=='2'){
      this.setData({
        pingj:2
      })
    }
    else if(this.data.flag=='3'){
      this.setData({
        pingj:3
      })
    }
    else if(this.data.flag=='4'){
      this.setData({
        pingj:4
      })
    }
    else{
      this.setData({
        pingj:5
      })
    };
    db.collection('order').doc(this.data.id).update({
      data:{
        evrepair: this.data.pingj,
        ddzt:'订单已完成'
      }
    }).then(res=>{
      wx.showToast({
        title:'评价成功',
        icon:'success',
      });
      setTimeout(function () {
        wx.navigateBack({
          delta: 2
        })
      }, 2000);
    }).catch(err=>{
      wx.showToast({
        title:'评价失败',
        icon:'none'
      })
    })
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {
    this.setData({
      id:options.id,
    })
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